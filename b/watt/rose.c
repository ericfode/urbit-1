/* watt/rose.c
**
** This file is in the public domain.
*/
#include "u4/all.h"

/* both:rose:crow
*/
u4_type
_rose_both(u4_crow p,
           u4_type sub,
           u4_type hoc)
{
  u4_lane lan = p->lan;

#if 1
  if ( u4_n_eq(u4_atom_blur, sub) ) {
    return hoc;
  }
  else if ( u4_n_eq(u4_atom_blur, hoc) ) {
    return sub;
  }
  else {
    return u4_kt(lan, u4_atom_fuse, hoc, sub);
  }
#else 
  if ( u4_so(_iris_nest(p, hoc, u4_noun_0, u4_noun_1, sub)) ) {
    /* every sub is a hoc */
    return sub;
  }
  else {
    /* not every sub is a hoc */
    if ( u4_so(_iris_nest(p, sub, u4_noun_0, u4_noun_1, hoc)) ) {
      /* every hoc is a sub */
      return hoc;
    }
    else {
      /* not every sub is a hoc, not every hoc is a sub */
      return u4_kt(lan, u4_atom_fuse, hoc, sub);
    }
  }
#endif
}

/* eith:rose:crow
*/
u4_type
_rose_eith(u4_crow p,
           u4_type sub,
           u4_type hoc)
{
  u4_lane lan = p->lan;

  if ( u4_n_eq(u4_atom_blot, hoc) ) {
    return sub;
  }
  else if ( u4_n_eq(u4_atom_blot, sub) ) {
    return hoc;
  }
  else return u4_kt(lan, u4_atom_fork, sub, hoc);
}

/* etch:rose:crow
*/
u4_type
_rose_etch(u4_crow p,
           u4_type sub)
{
  u4_noun p_sub, q_sub;

  if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
    return q_sub;
  }
  else return _crow_fail(p, "bad etch");
}
/* fine:rose:crow
*/
  static u4_flag
  _rose_fine_hard(u4_crow p,
                  u4_type sub,
                  u4_spec dab)
  {
    u4_noun p_dab, q_dab;

    if ( u4_b_p(dab, u4_atom_none, &p_dab) ) {
      return u4_yes;
    }
    else if ( u4_b_pq(dab, u4_atom_leaf, &p_dab, &q_dab) ) {
      return _rose_show(p, sub, q_dab);
    }
    else if ( u4_b_fork(dab, &p_dab, &q_dab) ) {
      return 
        u4_and(_rose_fine_hard(p, sub, p_dab), 
               _rose_fine_hard(p, sub, q_dab));
    }
    else return u4_trip;
  } 
  static u4_flag
  _rose_fine_soft(u4_crow p,
                  u4_type sub,
                  u4_type gar,
                  u4_spec dab)
  {
    u4_noun p_dab, q_dab;

    if ( u4_b_p(dab, u4_atom_none, &p_dab) ) {
      return u4_yes;
    }
    else if ( u4_b_pq(dab, u4_atom_leaf, &p_dab, &q_dab) ) {
      if ( !_rose_show(p, sub, q_dab) ) {
        return u4_no;
      }
      else {
        u4_tool vac = _rose_make(p, sub, q_dab);
        u4_tool foh = _rose_make(p, gar, q_dab);

        if ( !u4_n_eq(vac, foh) ) {
          printf("soft foh!\n");
          u4_brut(p, "sub", sub);
          u4_brut(p, "gar", gar);
        }
        return u4_say(u4_n_eq(vac, foh));
      }
    }
    else if ( u4_b_fork(dab, &p_dab, &q_dab) ) {
      return 
        u4_and(_rose_fine_soft(p, sub, gar, p_dab), 
               _rose_fine_soft(p, sub, gar, q_dab));
    }
    else return u4_trip;
  }
u4_flag
_rose_fine(u4_crow p,
           u4_type sub)
{
  u4_lane lan = p->lan;
  u4_noun p_sub, q_sub, pq_sub, qq_sub;

  if ( !u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
    return u4_trip;
  }
  else {
    if ( u4_b_p(q_sub, u4_atom_hard, &pq_sub) ) {
      return _rose_fine_hard(p, sub, pq_sub);
    }
    else if ( u4_b_pq(q_sub, u4_atom_soft, &pq_sub, &qq_sub) ) {
      if ( u4_bag_in(sub, p->ver) ) {
        return u4_yes;
      }
      else {
        u4_noun gar = u4_kt(lan, u4_atom_core, pq_sub, q_sub);
        u4_pool ver;
        u4_flag dem;

        ver = p->ver;
        p->ver = u4_bag_add(lan, sub, p->ver);
        dem = _rose_fine_soft(p, sub, gar, qq_sub);

        p->ver = ver;
        return dem;
      }
    }
    else return u4_trip;
  }
}

/* edit:rose:crow
*/
u4_type
_rose_edit(u4_crow p,
           u4_type sub,
           u4_list mut)
{
  u4_tack tac = _lark_feed(p, sub, u4_noun_0, mut);
  u4_type fuz = _iris_burn(p, sub, u4_noun_0, u4_noun_1, u4_no, tac);

  return fuz;
}

/* gain:rose:crow
*/
  static u4_rack
  _rose_gain_hunt(u4_crow, u4_type, u4_gene);

  static u4_rack
  _rose_gain_hunt_a(u4_crow p,
                    u4_type sub,
                    u4_bank vof)
  {
    if ( u4_n_zero(vof) ) {
      return u4_noun_0;
    }
    else return u4_log_cat(p->lan, _rose_gain_hunt(p, sub, u4_ch(vof)),
                                   _rose_gain_hunt_a(p, sub, u4_ct(vof)));
  }
  static u4_plot
  _rose_gain_hunt(u4_crow p,
                  u4_type sub,
                  u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_noun p_gen, q_gen;

    if ( u4_b_pq(gen, u4_atom_like, &p_gen, &q_gen) ) {
      return u4_k_cell
        (lan, 
         u4_k_cell(lan, q_gen, _rose_play(p, sub, p_gen)),
         u4_noun_0);
    }
    else if ( u4_b_p(gen, u4_atom_sand, &p_gen) ) {
      return _rose_gain_hunt_a(p, sub, p_gen);
    }
    else return u4_noun_0;
  }
  static u4_type
  _rose_gain_gild(u4_crow p,
                  u4_type sub,
                  u4_plot mut)
  {
    u4_tack tac = _lark_feed(p, sub, u4_noun_0, mut);
    u4_type hoc = _iris_burn(p, u4_atom_blur, u4_noun_0, u4_noun_1, u4_no, tac);

#if 0
    u4_err(p->lan, "gain: tac", tac);
    u4_brut(p, "gain: hoc", hoc);
    u4_brut(p, "gain: sub", sub);
    printf("\n");
#endif
    return _rose_both(p, sub, hoc);
  }
u4_type
_rose_gain(u4_crow p,
           u4_type sub,
           u4_gene gen)
{
  u4_plot zet = _rose_gain_hunt(p, sub, gen);
#if 0
  u4_err(p->lan, "gain: zet", zet);
#endif
  return _rose_gain_gild(p, sub, zet);
}

/* make:rose:crow
*/
  u4_tool
  _rose_make_boil_a(u4_crow p,
                    u4_type sub,
                    u4_list rem)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(rem) ) {
      return u4_noun_0;
    }
    else {
      u4_noun i_rem  = u4_ch(rem);
      u4_noun t_rem  = u4_ct(rem);
      u4_gene pi_rem = u4_ch(i_rem);
      u4_tool qi_rem = u4_ct(i_rem);
      u4_plan giz    = _rose_seek(p, sub, _crow_rake(p, pi_rem));
      u4_axis p_giz  = u4_ch(giz);

      return u4_k_cell(lan, u4_k_cell(lan, p_giz, qi_rem),
                            _rose_make_boil_a(p, sub, t_rem));
    }
  }
  u4_tool
  _rose_make_boil(u4_crow p,
                  u4_type sub,
                  u4_axis axe,
                  u4_list rem)
  {
    return _lily_hike(p, axe, _rose_make_boil_a(p, sub, rem));
  }
  u4_tool 
  _rose_make_bake(u4_crow p,
                  u4_type sub,
                  u4_spec sep)
  {
    u4_lane lan = p->lan;
    u4_noun p_sep, q_sep;

    if ( u4_b_fork(sep, &p_sep, &q_sep) ) {
      return u4_k_cell(lan, _rose_make_bake(p, sub, p_sep),
                            _rose_make_bake(p, sub, q_sep));
    }
    else if ( u4_b_p(sep, u4_atom_none, &p_sep) ) {
      return u4_k_cell(lan, u4_noun_0, u4_noun_0);
    }
    else if ( u4_b_pq(sep, u4_atom_leaf, &p_sep, &q_sep) ) {
      return _rose_make(p, sub, q_sep);
    }
    else {
      return u4_trip;
    }
  }
  u4_noun
  _rose_make_a(u4_crow p,
               u4_type sub,
               u4_rack dus)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(dus) ) {
      return u4_noun_0;
    }
    else {
      u4_noun i_dus = u4_ch(dus);
      u4_noun t_dus = u4_ct(dus);
      u4_gene pi_dus = u4_ch(i_dus);
      u4_gene qi_dus = u4_ct(i_dus);
      u4_tool pog    = _rose_make(p, sub, qi_dus);

      return u4_k_cell
        (lan,
         u4_k_cell(lan, pi_dus, pog),
         _rose_make_a(p, sub, t_dus));
    }
  }
  static u4_tool
  _rose_make_main(u4_crow p,
                  u4_type sub,
                  u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_noun p_gen, q_gen, r_gen;

    if ( u4_b_p(gen, u4_atom_bail, &p_gen) ) {
      return u4_k_cell(lan, u4_noun_0, u4_noun_0);
    }
    else if ( u4_b_p(gen, u4_atom_boot, &p_gen) ) {
      return u4_trip;
    }
    else if ( u4_b_p(gen, u4_atom_bump, &p_gen) ) {
      return u4_k_cell(lan, u4_noun_5, _rose_make(p, sub, p_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
      return _rose_make(p, sub, q_gen);
    }
    else if ( u4_b_pq(gen, u4_atom_cell, &p_gen, &q_gen) ) {
      return _lily_cons
        (p, _rose_make(p, sub, p_gen), _rose_make(p, sub, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_cool, &p_gen) ) {
      return _rose_make(p, sub, p_gen);
    }
    else if ( u4_b_p(gen, u4_atom_dbug, &p_gen) ) {
      u4_tool guz;
      u4_atom bug;

      bug = p->bug;
      p->bug = u4_op_inc(lan, p->bug);

      guz = _rose_make(p, sub, p_gen);
      
      p->bug = bug;
      return guz;
    }
    else if ( u4_b_p(gen, u4_atom_deep, &p_gen) ) {
      return u4_k_cell(lan, u4_noun_4, _rose_make(p, sub, p_gen));
    }
    else if ( u4_b_p(gen, u4_atom_etch, &p_gen) ) {
      return _rose_make(p, sub, p_gen);
    }
    else if ( u4_b_pq(gen, u4_atom_home, &p_gen, &q_gen) ) {
      u4_noun syq = p->nix;
      u4_noun qip;

      p->nix = p_gen;
      qip = _rose_make(p, sub, q_gen);
      p->nix = syq;

      return qip;
    }
    else if ( u4_b_p(gen, u4_atom_lift, &p_gen) ) {
      u4_spec sec = _gull_fill(p, u4_kc(lan, u4_atom_none, u4_noun_0), p_gen);
      u4_noun baf = _rose_make_bake(p, _rose_play(p, sub, gen), sec);

      return u4_kc
        (lan,
         u4_kc(lan, u4_noun_0, u4_noun_1), 
         u4_kc(lan, u4_noun_1, baf));
    }
    else if ( u4_b_pq(gen, u4_atom_like, &p_gen, &q_gen) ) {
      u4_plan lar = _rose_seek(p, sub, _crow_rake(p, q_gen));
      u4_axis p_lar = u4_ch(lar);

      if ( !u4_n_zero(u4_ch(u4_ct(lar))) ) {
        return _crow_fail(p, "bad like");
      }
      else {
        return _iris_fish(p, _rose_play(p, sub, p_gen), u4_noun_0, p_lar);
      }
    }
    else if ( u4_b_pq(gen, u4_atom_link, &p_gen, &q_gen) ) {
      return _lily_comb
        (p,
         _rose_make(p, sub, p_gen),
         _rose_make(p, _rose_play(p, sub, p_gen), q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_load, &p_gen) ) {
      u4_spec sec = _gull_fill(p, u4_kc(lan, u4_atom_none, u4_noun_0), p_gen);
      u4_noun baf = _rose_make_bake(p, _rose_play(p, sub, gen), sec);

      return u4_kc
        (lan,
         u4_kc(lan, u4_noun_0, u4_noun_1), 
         u4_kc(lan, u4_noun_1, baf));
    }
    else if ( u4_b_p(gen, u4_atom_meta, &p_gen) ) {
      return u4_trip;
    }
    else if ( u4_b_pq(gen, u4_atom_name, &p_gen, &q_gen) ) {
      return _rose_make(p, sub, q_gen);
    }
    else if ( u4_b_p(gen, u4_atom_nock, &p_gen) ) {
      return u4_k_cell(lan, u4_noun_3, _rose_make(p, sub, p_gen));
    }
    else if ( u4_b_p(gen, u4_atom_rock, &p_gen) ) {
      return u4_k_cell(lan, u4_noun_1, p_gen);
    }
    else if ( u4_b_pq(gen, u4_atom_spot, &p_gen, &q_gen) ) {
      u4_noun muw = p->zud;
      u4_noun qip;

      p->zud = p_gen;
      qip = _rose_make(p, sub, q_gen);
      p->zud = muw;

      return qip;
    }
    else if ( u4_b_pq(gen, u4_atom_sure, &p_gen, &q_gen) ) {
      return u4_kc(lan, u4_noun_0, u4_noun_1);
    }
    else if ( u4_b_pq(gen, u4_atom_take, &p_gen, &q_gen) ) {
      u4_plan lar = _rose_seek(p, sub, p_gen);
      u4_noun rem = _rose_make_a(p, sub, q_gen);
      u4_axis p_lar = u4_ch(lar);
      u4_noun q_lar = u4_ch(u4_ct(lar));
      u4_type r_lar = u4_ct(u4_ct(lar));

#if 0
      if ( !u4_n_zero(q_gen) ) {
        u4_err(lan, "make: take", gen);
        u4_err(lan, "make: q", q_lar);
      }
#endif
      if ( u4_n_zero(q_lar) ) {
        return _rose_make_boil(p, r_lar, p_lar, rem);
      }
      else {
        u4_door uq_lar  = u4_ct(q_lar);
        u4_axis puq_lar = u4_ch(uq_lar);
        u4_type quq_lar = u4_ch(u4_ct(uq_lar));
        u4_tool ruz = _rose_make_boil(p, quq_lar, p_lar, rem);
        u4_tool gak;

        gak = u4_k_trel
          (lan,
           u4_noun_3,
           ruz,
           u4_k_cell(lan, u4_noun_0, u4_op_peg(lan, p_lar, puq_lar)));

        return gak;
      }
    }
    else if ( u4_b_pqr(gen, u4_atom_test, &p_gen, &q_gen, &r_gen) ) {
      return u4_k_qual
        (lan,
         u4_noun_2,
         _rose_make(p, sub, p_gen),
         _rose_make(p, _rose_gain(p, sub, p_gen), q_gen),
         _rose_make(p, sub, r_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_twin, &p_gen, &q_gen) ) {
      return u4_k_trel
        (lan,
         u4_noun_6,
         _rose_make(p, sub, p_gen),
         _rose_make(p, sub, q_gen));
    }
    else {
      u4_noun fog = _crow_open(p, gen);

      if ( u4_n_eq(fog, gen) ) {
        u4_err(lan, "dup: gen", gen);
        return u4_trip;
      }
      return _rose_make(p, sub, _crow_open(p, gen)); 
    }
  }
u4_tool
_rose_make(u4_crow p,
           u4_type sub,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_noun mum = u4_kc(lan, sub, gen);
  u4_nopt zod = u4_tab_get(mum, p->niq);

  if ( zod != u4_bull ) {
    return zod;
  }
  else {
    u4_tool gur = _rose_make_main(p, sub, gen);

    p->niq = u4_tab_add(lan, mum, gur, p->niq);
    return gur;
  }
}

/* null:rose:crow
*/
  static u4_flag
  _rose_null_a(u4_crow p,
               u4_type sub,
               u4_pool hem)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;

    if ( u4_n_eq(sub, u4_atom_atom) ) {
      return u4_no;
    }
    else if ( u4_n_eq(sub, u4_atom_blur) ) {
      return u4_no;
    }
    else if ( u4_n_eq(sub, u4_atom_blot) ) {
      return u4_yes;
    }
    else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
      return u4_or(_rose_null_a(p, p_sub, hem), _rose_null_a(p, q_sub, hem));
    }
    else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
      return _rose_null_a(p, p_sub, hem);
    }
    else if ( u4_b_p(sub, u4_atom_cube, &p_sub) ) {
      return u4_no;
    }
    else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      return _rose_null_a(p, q_sub, hem);
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      return u4_and(_rose_null_a(p, p_sub, hem), _rose_null_a(p, q_sub, hem));
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      return _rose_orth(p, p_sub, q_sub);
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      if ( u4_bag_in(sub, hem) ) {
        return u4_yes;
      } else {
        return _rose_null_a
          (p, _rose_repo(p, p_sub, q_sub), u4_bag_add(lan, sub, hem));
      }
    } 
    else return u4_trip;
  }
u4_flag
_rose_null(u4_crow p,
           u4_type sub)
{
  return _rose_null_a(p, sub, u4_noun_0);
}

/* orth:rose:crow
*/
  static u4_flag
  _rose_orth_a(u4_crow p,
               u4_type sub,
               u4_type ref,
               u4_pool bol)
  {
    u4_lane lan = p->lan;
    u4_noun p_sub, q_sub;
    u4_noun p_ref, q_ref;

    if ( u4_n_eq(sub, u4_atom_atom) ) {
      if ( u4_n_eq(ref, u4_atom_atom) ) {
        return u4_no;
      }
      else if ( u4_b_pq(ref, u4_atom_cell, &p_sub, &q_sub) ) {
        return u4_yes;
      }
      else return _rose_orth_a(p, ref, sub, bol);
    }
    else if ( u4_n_eq(sub, u4_atom_blur) ) {
      return u4_no;
    }
    else if ( u4_b_pq(sub, u4_atom_cell, &p_sub, &q_sub) ) {
      if ( u4_b_pq(ref, u4_atom_cell, &p_ref, &q_ref) ) {
        return u4_or(_rose_orth_a(p, p_sub, p_ref, bol),
                     _rose_orth_a(p, q_sub, q_ref, bol));
      }
      else {
        return _rose_orth_a(p, ref, sub, bol);
      }
    }
    else if ( u4_b_pq(sub, u4_atom_core, &p_sub, &q_sub) ) {
      return _rose_orth_a
        (p, u4_k_trel(lan, u4_atom_cell, p_sub, u4_atom_blur), ref, bol);
    }
    else if ( u4_b_p(sub, u4_atom_cube, &p_sub) ) {
      if ( u4_n_eq(u4_atom_atom, ref) ) {
        return u4_n_atom(p_sub) ? u4_no : u4_yes;
      }
      else if ( u4_b_p(ref, u4_atom_cube, &p_ref) ) {
        return u4_say(!u4_n_eq(p_sub, p_ref));
      }
      else if ( u4_b_pq(ref, u4_atom_cell, &p_ref, &q_ref) ) {
        if ( u4_n_atom(p_sub) ) {
          return u4_yes;
        } else {
          u4_type hed = u4_k_cell(lan, u4_atom_cube, u4_ch(p_sub));
          u4_type tal = u4_k_cell(lan, u4_atom_cube, u4_ct(p_sub));

          return u4_or(_rose_orth_a(p, hed, p_ref, bol),
                       _rose_orth_a(p, tal, q_ref, bol));
        }
      }
      else {
        return _rose_orth_a(p, ref, sub, bol);
      }
    }
    else if ( u4_b_pq(sub, u4_atom_face, &p_sub, &q_sub) ) {
      return _rose_orth_a(p, q_sub, ref, bol);
    }
    else if ( u4_b_pq(sub, u4_atom_fork, &p_sub, &q_sub) ) {
      return u4_and(_rose_orth_a(p, p_sub, ref, bol),
                    _rose_orth_a(p, q_sub, ref, bol));
    }
    else if ( u4_b_pq(sub, u4_atom_fuse, &p_sub, &q_sub) ) {
      return u4_or(_rose_orth_a(p, p_sub, ref, bol),
                   _rose_orth_a(p, q_sub, ref, bol));
    }
    else if ( u4_b_pq(sub, u4_atom_hold, &p_sub, &q_sub) ) {
      u4_noun gob = u4_k_cell(lan, sub, ref);

      if ( u4_bag_in(gob, bol) ) {
        return u4_yes;
      } else {
        return _rose_orth_a
          (p, _rose_repo(p, p_sub, q_sub), ref, u4_bag_add(lan, gob, bol));
      }
    } 
    else return u4_trip;
  }
u4_flag
_rose_orth(u4_crow p,
           u4_type sub,
           u4_type ref)
{
  u4_lane lan = p->lan;
  u4_noun mum = u4_kc(lan, sub, ref);
  u4_nopt zod = u4_tab_get(mum, p->gam);

  if ( zod != u4_bull ) {
    return zod;
  }
  else {
    u4_flag gur = _rose_orth_a(p, sub, ref, u4_noun_0);

    p->gam = u4_tab_add(lan, mum, gur, p->gam);
    return gur;
  }
}

/* play:rose:crow
*/
  static u4_plot
  _rose_play_a(u4_crow p,
               u4_type sub,
               u4_rack dus)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(dus) ) {
      return u4_noun_0;
    }
    else {
      u4_noun i_dus = u4_ch(dus);
      u4_noun t_dus = u4_ct(dus);
      u4_gene pi_dus = u4_ch(i_dus);
      u4_gene qi_dus = u4_ct(i_dus);
      u4_type feg    = _rose_play(p, sub, qi_dus);

      return u4_k_cell
        (lan,
         u4_k_cell(lan, pi_dus, feg),
         _rose_play_a(p, sub, t_dus));
    }
  }
  static u4_type
  _rose_play_main(u4_crow p,
                  u4_type sub,
                  u4_gene gen)
  {
    u4_lane lan = p->lan;
    u4_noun p_gen, q_gen, r_gen;

    if ( u4_b_p(gen, u4_atom_bail, &p_gen) ) {
      return u4_atom_blot;
    }
    else if ( u4_b_p(gen, u4_atom_boot, &p_gen) ) {
      return u4_trip;
    }
    else if ( u4_b_p(gen, u4_atom_bump, &p_gen) ) {
      return u4_atom_atom;
    }
    else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
      return _rose_play(p, sub, p_gen);
    }
    else if ( u4_b_pq(gen, u4_atom_cell, &p_gen, &q_gen) ) {
      return u4_k_trel
        (lan, u4_atom_cell,
              _rose_play(p, sub, p_gen),
              _rose_play(p, sub, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_cool, &p_gen) ) {
      return _rose_play(p, sub, p_gen);
    }
    else if ( u4_b_p(gen, u4_atom_dbug, &p_gen) ) {
      u4_type soq;
      u4_atom bug;

      bug = p->bug;
      p->bug = u4_op_inc(lan, p->bug);

      soq = _rose_play(p, sub, p_gen);
      
      p->bug = bug;
      return soq;
    }
    else if ( u4_b_p(gen, u4_atom_deep, &p_gen) ) {
      return u4_k_trel
        (lan,
         u4_atom_fork,
         u4_k_cell(lan, u4_atom_cube, u4_noun_0),
         u4_k_cell(lan, u4_atom_cube, u4_noun_1));
    }
    else if ( u4_b_p(gen, u4_atom_etch, &p_gen) ) {
      return _rose_etch(p, _rose_play(p, sub, p_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_home, &p_gen, &q_gen) ) {
      u4_noun syq = p->nix;
      u4_noun qip;

      p->nix = p_gen;
      qip = _rose_play(p, sub, q_gen);
      p->nix = syq;

      return qip;
    }
    else if ( u4_b_p(gen, u4_atom_lift, &p_gen) ) {
      return u4_k_trel
        (lan, u4_atom_core, 
              sub, 
              u4_k_trel
                (lan,
                 u4_atom_soft,
                 sub,
                 _gull_fill(p, u4_kc(lan, u4_atom_none, u4_noun_0), p_gen)));
    }
    else if ( u4_b_pq(gen, u4_atom_like, &p_gen, &q_gen) ) {
      return u4_k_trel
        (lan,
         u4_atom_fork,
         u4_k_cell(lan, u4_atom_cube, u4_noun_0),
         u4_k_cell(lan, u4_atom_cube, u4_noun_1));
    }
    else if ( u4_b_pq(gen, u4_atom_link, &p_gen, &q_gen) ) {
      return _rose_play(p, _rose_play(p, sub, p_gen), q_gen);
    }
    else if ( u4_b_p(gen, u4_atom_load, &p_gen) ) {
      return u4_kt
        (lan, u4_atom_core,
              sub,
              u4_k_cell
                (lan, 
                 u4_atom_hard,
                 _gull_fill(p, u4_kc(lan, u4_atom_none, u4_noun_0), p_gen)));
    }
    else if ( u4_b_p(gen, u4_atom_meta, &p_gen) ) {
      return u4_trip;
    }
    else if ( u4_b_pq(gen, u4_atom_name, &p_gen, &q_gen) ) {
      return u4_k_trel(lan, u4_atom_face, p_gen, _rose_play(p, sub, q_gen));
    }
    else if ( u4_b_p(gen, u4_atom_nock, &p_gen) ) {
      return u4_atom_blur;
    }
    else if ( u4_b_p(gen, u4_atom_rock, &p_gen) ) {
      return u4_k_cell(lan, u4_atom_cube, p_gen); 
    }
    else if ( u4_b_pq(gen, u4_atom_spot, &p_gen, &q_gen) ) {
      u4_noun muw = p->zud;
      u4_noun qip;

      p->zud = p_gen;
      qip = _rose_play(p, sub, q_gen);
      p->zud = muw;

      return qip;
    }
    else if ( u4_b_pq(gen, u4_atom_sure, &p_gen, &q_gen) ) {
      return sub;
    }
    else if ( u4_b_pq(gen, u4_atom_take, &p_gen, &q_gen) ) {
      u4_plan lar = _rose_seek(p, sub, p_gen);
      u4_noun huz = _rose_play_a(p, sub, q_gen);
      u4_noun q_lar = u4_ch(u4_ct(lar));
      u4_type r_lar = u4_ct(u4_ct(lar));

      if ( u4_n_zero(q_lar) ) {
        return _rose_edit(p, r_lar, huz);
      }
      else {
        u4_door uq_lar  = u4_ct(q_lar);
        u4_type quq_lar = u4_ch(u4_ct(uq_lar));
        u4_type ruq_lar = u4_ct(u4_ct(uq_lar));

        return u4_k_trel
          (lan,
           u4_atom_hold,
           _rose_edit(p, quq_lar, huz),
           ruq_lar);
      }
    }
    else if ( u4_b_pqr(gen, u4_atom_test, &p_gen, &q_gen, &r_gen) ) {
      return _rose_eith
        (p,
         _rose_play(p, _rose_gain(p, sub, p_gen), q_gen),
         _rose_play(p, sub, r_gen));
    }
    else if ( u4_b_pq(gen, u4_atom_twin, &p_gen, &q_gen) ) {
      return u4_k_trel
        (lan,
         u4_atom_fork,
         u4_k_cell(lan, u4_atom_cube, u4_noun_0),
         u4_k_cell(lan, u4_atom_cube, u4_noun_1));
    }
    else {
      return _rose_play(p, sub, _crow_open(p, gen)); 
    }
  }
u4_type
_rose_play(u4_crow p,
           u4_type sub,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_noun mum = u4_kc(lan, sub, gen);
  u4_nopt zod = u4_tab_get(mum, p->zor);

  if ( zod != u4_bull ) {
    return zod;
  }
  else {
    u4_type gur = _rose_play_main(p, sub, gen);

    p->zor = u4_tab_add(lan, mum, gur, p->zor);
    return gur;
  }
}

/* repo:rose:crow
*/
u4_type
_rose_repo(u4_crow p,
           u4_type sub,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_noun vax = u4_k_cell(lan, sub, gen);

  if ( u4_bag_in(vax, p->fan) ) {
    return _crow_fail(p, "inference recursion");
  }
  else {
    u4_noun fan;
    u4_type gex;

    fan = p->fan;
    p->fan = u4_bag_add(lan, vax, p->fan);

    gex = _rose_play(p, sub, gen);
    p->fan = fan;
    return gex;
  }
}

/* safe:rose:crow
*/
u4_flag
_rose_safe(u4_crow p,
           u4_type sub,
           u4_plot mut)
{
  u4_tack tac = _lark_feed(p, sub, u4_noun_0, mut);

  _iris_burn(p, sub, u4_noun_0, u4_noun_1, u4_yes, tac);
  return u4_yes;
}

/* seek:rose:crow
*/
  static u4_plan
  _rose_seek_a(u4_crow p,
               u4_type sub,
               u4_rope rop,
               u4_axis axe,
               u4_unit act)
  {
    u4_lane lan = p->lan;

    if ( u4_n_zero(rop) ) {
      return u4_k_trel(lan, axe, act, sub);
    }
    else {
      u4_noun i_rop = u4_ch(rop);
      u4_noun t_rop = u4_ct(rop);
      u4_noun pi_rop;

      if ( u4_n_atom(i_rop) ) {
        return _rose_seek_a
          (p, sub, 
              u4_k_cell(lan, u4_k_cell(lan, u4_atom_port, i_rop), t_rop),
              axe,
              act);
      }
      else if ( u4_b_p(i_rop, u4_atom_frag, &pi_rop) ) {
        return _rose_seek_a
          (p, _iris_peek(p, sub, u4_noun_0, u4_noun_1, pi_rop), 
              t_rop,
              u4_op_peg(lan, axe, pi_rop),
              u4_noun_0);
      }
      else if ( u4_b_p(i_rop, u4_atom_port, &pi_rop) ) {
        u4_plan sap = _iris_find(p, sub, u4_noun_0, u4_noun_1, pi_rop);
        u4_axis p_sap = u4_ch(sap);
        u4_unit q_sap = u4_ch(u4_ct(sap));
        u4_type r_sap = u4_ct(u4_ct(sap));
#if 0
        if ( u4_n_zero(pi_rop) ) {
          u4_err(lan, "blip: p", p_sap);
          u4_err(lan, "blip: q", q_sap);
          u4_err(lan, "blip: r", r_sap);
        }
#endif
        return _rose_seek_a
          (p, r_sap, t_rop, u4_op_peg(lan, axe, p_sap), q_sap);
      }
      else if ( u4_b_p(i_rop, u4_atom_pith, &pi_rop) ) {
        u4_plan sap = _iris_find(p, sub, u4_noun_0, u4_noun_1, pi_rop);
        u4_axis p_sap = u4_ch(sap);
        u4_type r_sap = u4_ct(u4_ct(sap));
        
        return _rose_seek_a
          (p, r_sap, t_rop, u4_op_peg(lan, axe, p_sap), u4_noun_0);
      }
      else return u4_trip;
    }
  }
u4_plan
_rose_seek(u4_crow p,
           u4_type sub,
           u4_rope rop)
{
  return _rose_seek_a(p, sub, rop, u4_noun_1, u4_noun_0);
}

/* show:rose:crow
*/
  u4_flag
  _rose_show_nest(u4_crow p,
                  u4_type sub,
                  u4_type bon)
  {
    if ( !u4_so(_iris_nest(p, sub, u4_noun_0, u4_noun_1, bon)) ) {
      printf("\n\n");
      u4_brut(p, "nest: sub", sub);
      u4_brut(p, "nest: bon", bon);
      return _crow_fail(p, "nest: show");
    }
    else return u4_yes;
  }
u4_flag
_rose_show(u4_crow p,
           u4_type sub,
           u4_gene gen)
{
  u4_lane lan = p->lan;
  u4_noun p_gen, q_gen, r_gen;

  if ( u4_b_p(gen, u4_atom_bail, &p_gen) ) {
    return u4_yes;
  }
  else if ( u4_b_p(gen, u4_atom_boot, &p_gen) ) {
    return u4_yes;
  }
  else if ( u4_b_p(gen, u4_atom_bump, &p_gen) ) {
    return u4_and(_rose_show(p, sub, p_gen),
                  _rose_show_nest(p, u4_atom_atom, _rose_play(p, sub, p_gen)));
  }
  else if ( u4_b_pq(gen, u4_atom_cast, &p_gen, &q_gen) ) {
    return u4_and
      (_rose_show(p, sub, p_gen),
       u4_and
        (_rose_show(p, sub, q_gen),
         _rose_show_nest(p, _rose_play(p, sub, p_gen),
                            _rose_play(p, sub, q_gen))));
  }
  else if ( u4_b_pq(gen, u4_atom_cell, &p_gen, &q_gen) ) {
    return u4_and(_rose_show(p, sub, p_gen), _rose_show(p, sub, q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_cool, &p_gen) ) {
    return _rose_show(p, sub, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_dbug, &p_gen) ) {
    u4_flag zic;
    u4_atom bug;

    bug = p->bug;
    p->bug = u4_op_inc(lan, p->bug);

    zic = _rose_show(p, sub, p_gen);
    
    p->bug = bug;
    return zic;
  }
  else if ( u4_b_p(gen, u4_atom_deep, &p_gen) ) {
    return _rose_show(p, sub, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_etch, &p_gen) ) {
    return _rose_show(p, sub, p_gen);
  }
  else if ( u4_b_pq(gen, u4_atom_home, &p_gen, &q_gen) ) {
    u4_noun syq = p->nix;
    u4_noun qip;

    p->nix = p_gen;
    qip = _rose_show(p, sub, q_gen);
    p->nix = syq;

    return qip;
  }
  else if ( u4_b_p(gen, u4_atom_lift, &p_gen) ) {
    return u4_yes;
  }
  else if ( u4_b_pq(gen, u4_atom_like, &p_gen, &q_gen) ) {
    return u4_and(_rose_show(p, sub, p_gen), 
                  _rose_show(p, sub, q_gen));
  }
  else if ( u4_b_pq(gen, u4_atom_link, &p_gen, &q_gen) ) {
    return u4_and(_rose_show(p, sub, p_gen),
                  _rose_show(p, _rose_play(p, sub, p_gen), q_gen));
  }
  else if ( u4_b_p(gen, u4_atom_load, &p_gen) ) {
    return _rose_fine(p, _rose_play(p, sub, gen)); 
  }
  else if ( u4_b_p(gen, u4_atom_meta, &p_gen) ) {
    return u4_trip;
  }
  else if ( u4_b_pq(gen, u4_atom_name, &p_gen, &q_gen) ) {
    return _rose_show(p, sub, q_gen);
  }
  else if ( u4_b_p(gen, u4_atom_nock, &p_gen) ) {
    return _rose_show(p, sub, p_gen);
  }
  else if ( u4_b_p(gen, u4_atom_rock, &p_gen) ) {
    return u4_yes;
  }
  else if ( u4_b_pq(gen, u4_atom_spot, &p_gen, &q_gen) ) {
    u4_noun muw = p->zud;
    u4_noun qip;

    p->zud = p_gen;
    qip = _rose_show(p, sub, q_gen);
    p->zud = muw;

    return qip;
  }
  else if ( u4_b_pq(gen, u4_atom_sure, &p_gen, &q_gen) ) {
    return u4_and
      (_rose_show(p, sub, p_gen),
       u4_and
        (_rose_show(p, sub, q_gen),
         _rose_show_nest
          (p, _rose_play(p, sub, p_gen), _rose_play(p, sub, q_gen))));
  }
  else if ( u4_b_pq(gen, u4_atom_take, &p_gen, &q_gen) ) {
    u4_plan lar = _rose_seek(p, sub, p_gen);
    u4_noun huz = _rose_play_a(p, sub, q_gen);
    u4_noun q_lar = u4_ch(u4_ct(lar));
    u4_type r_lar = u4_ct(u4_ct(lar));

    if ( u4_n_zero(q_lar) ) {
      return _rose_safe(p, r_lar, huz);
    }
    else {
      u4_door uq_lar  = u4_ct(q_lar);
      u4_type quq_lar = u4_ch(u4_ct(uq_lar));

      return _rose_safe(p, quq_lar, huz);
    }
  }
  else if ( u4_b_pqr(gen, u4_atom_test, &p_gen, &q_gen, &r_gen) ) {
    return u4_and
      (_rose_show(p, sub, p_gen),
       u4_and
       (_rose_show(p, _rose_gain(p, sub, p_gen), q_gen),
        _rose_show(p, sub, r_gen)));
  }
  else if ( u4_b_pq(gen, u4_atom_twin, &p_gen, &q_gen) ) {
    return u4_and
      (_rose_show(p, sub, p_gen),
       _rose_show(p, sub, q_gen));
  }
  else {
    u4_gene vul = _crow_open(p, gen);

    // u4_err(lan, "gen", gen);
    // u4_err(lan, "vul", vul);

    return _rose_show(p, sub, vul);
  }
}
