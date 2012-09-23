/* v/walk.c
**
**  This file is in the public domain.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <setjmp.h>
#include <gmp.h>
#include <dirent.h>
#include <stdint.h>
#include <ev.h>

#include "all.h"
#include "f/coal.h"
#include "v/vere.h"
  
  /*  |%
  **  ++  arch                                      ::  fs node
  **    $%  [& clod]                                ::  ie, file
  **        [| dirt]                                ::  ie, directory
  **    ==                                          ::
  **  ++  clod  ,[p=@da q=@uvI r=*]                 ::  mtime hash content
  **  ++  dirt  ,[p=@da q=(map ,@ta arch)]          ::  mtime tree
  **  --
  */

#if 0
static u2_noun
_walk_ok(u2_reck* rec_u, u2_noun nod)
{
  u2_noun don = u2_cn_mung(u2k(rec_u->toy.arch), u2k(nod));

  if ( u2_no == u2_sing(nod, don) ) {
    c3_assert(0);
  }
  u2z(don);
  return nod;
}
#endif

/* u2_walk_load(): load file or bail.
*/
u2_noun
u2_walk_load(c3_c* pas_c)
{
  struct stat buf_b;
  c3_i        fid_i = open(pas_c, O_RDONLY, 0644);
  c3_w        fln_w, red_w;
  c3_y*       pad_y;

  if ( (fid_i < 0) || (fstat(fid_i, &buf_b) < 0) ) {
    perror(pas_c);
    return u2_cm_bail(c3__fail);
  }
  fln_w = buf_b.st_size;
  pad_y = malloc(buf_b.st_size);

  red_w = read(fid_i, pad_y, fln_w);
  close(fid_i);

  if ( fln_w != red_w ) {
    free(pad_y);
    return u2_cm_bail(c3__fail);
  }
  else {
    u2_noun pad = u2_ci_bytes(fln_w, (c3_y *)pad_y); 
    free(pad_y);

    return pad;
  }
}

/* u2_walk_save(): save file or bail.
*/
void
u2_walk_save(c3_c* pas_c, u2_noun tim, u2_atom pad)
{
  c3_i  fid_i = open(pas_c, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  c3_w  fln_w, rit_w;
  c3_y* pad_y;

  if ( fid_i < 0 ) {
    perror(pas_c);
    u2_cm_bail(c3__fail);
  }

  fln_w = u2_met(3, pad);
  pad_y = malloc(fln_w);
  u2_cr_bytes(0, fln_w, pad_y, pad);
  u2z(pad);

  rit_w = write(fid_i, pad_y, fln_w);
  close(fid_i);
  free(pad_y);

  if ( rit_w != fln_w ) {
    perror(pas_c);
    u2_cm_bail(c3__fail);
  }

  if ( 0 != tim ) {
    struct timeval tim_tv[2];

    u2_time_out_tv(&tim_tv[0], u2k(tim));
    u2_time_out_tv(&tim_tv[1], tim);
 
    utimes(pas_c, tim_tv);
  }
}

/* _walk_in(): inner loop of _walk(), producing map.
*/
static u2_noun
_walk_in(u2_reck* rec_u, const c3_c* dir_c, c3_w len_w)
{
  DIR*    dir_d = opendir(dir_c);
  u2_noun map = u2_nul;

  if ( !dir_d ) {
    return u2_nul;
  }
  else while ( 1 ) {
    struct dirent  ent_n;
    struct dirent* out_n;

    if ( readdir_r(dir_d, &ent_n, &out_n) != 0 ) {
      perror(dir_c);
      break;
    } 
    else if ( !out_n ) {
      break;
    }
    else if ( !strcmp(out_n->d_name, ".") || 
              !strcmp(out_n->d_name, "..") ||
              ('.' == out_n->d_name[0]) )     //  XX restricts some spans
    {
      continue;
    }
    else {
      c3_c*  fil_c = out_n->d_name;
      c3_w   lef_w = len_w + 1 + strlen(fil_c);
      c3_c*  pat_c = malloc(lef_w + 1);
      struct stat buf_b;
   
      strcpy(pat_c, dir_c);
      pat_c[len_w] = '/';
      strcpy(pat_c + len_w + 1, fil_c);

      if ( 0 != stat(pat_c, &buf_b) ) {
        free(pat_c);
      } else {
        u2_noun tim = u2_time_in_ts(&buf_b.st_mtimespec);

        if ( !S_ISDIR(buf_b.st_mode) ) {
          c3_c* dot_c = strrchr(fil_c, '.');
          c3_c* nam_c = strdup(fil_c);
          c3_c* ext_c = strdup(dot_c + 1);

          nam_c[dot_c - fil_c] = 0;
          {
            u2_noun nam = u2_ci_string(nam_c);
            u2_noun ext = u2_ci_string(ext_c);
            u2_noun get = u2_ckd_by_get(u2k(map), u2k(nam));
            u2_noun dat = u2_walk_load(pat_c);
            u2_noun hax;

            if ( !strcmp("noun", ext_c) ) {
              dat = u2_cke_cue(dat);
            }
            hax = u2_cn_mung(u2k(rec_u->toy.sham), u2k(dat));
            if ( u2_none == get ) { get = u2_nul; }
           
            get = u2_ckd_by_put(get, ext, u2nq(u2_yes, u2k(tim), hax, dat));
            map = u2_ckd_by_put(map, nam, u2nt(u2_no, u2k(tim), get));
          }
          free(nam_c);
          free(ext_c);
        }
        else {
          u2_noun dir = _walk_in(rec_u, pat_c, lef_w);

          if ( u2_nul != dir ) {
            map = u2_ckd_by_put
              (map, u2_ci_string(fil_c), u2nt(u2_no, tim, dir));
          }
          else u2z(tim);
        }
      }
      free(pat_c);
    }
  }
  return map;
}

/* u2_walk(): traverse `dir_c` to produce an arch, updating `old`.
*/
u2_noun
u2_walk(u2_reck* rec_u, const c3_c* dir_c, u2_noun old)
{
  //  XX - obviously, cheaper to update old data.
  u2z(old);
  {
    struct stat buf_b;

    if ( 0 != stat(dir_c, &buf_b) ) {
      return u2_cm_bail(c3__fail);
    }
    else {
      return u2nt(u2_no, 
                  u2_time_in_ts(&buf_b.st_mtimespec),
                  _walk_in(rec_u, dir_c, strlen(dir_c)));
    }
  }
}