/* j/6/play.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  static u2_noun
  _play_flag(u2_wire wir_r)
  {
    return u2_bt(wir_r, c3__fork, u2_bc(wir_r, c3__cube, _0),
                                  u2_bc(wir_r, c3__cube, _1));
  }

  static u2_noun
  _play_in(u2_wire wir_r,
           u2_noun van,
           u2_noun sut,
           u2_noun gen)
  {
    u2_noun p_gen, q_gen, r_gen, s_gen;

    if ( u2_no == u2_dust(gen) ) {
      u2_noun rex = j2_mby(Pit, open)(wir_r, gen);

      pro = _play_in(wir_r, van, sut, rex);
      u2_rl_lose(wir_r, rex);
      return pro;
    } 
    else switch ( u2_h(gen) ) {
      default: {
        u2_noun rex = j2_mcy(Pit, ap, open)(wir_r, gen);

        pro = _play_in(wir_r, van, sut, rex);
        u2_rl_lose(wir_r, rex);
        return pro;
      }
      
      case c3__bnld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return _play_in(wir_r, van, _play_in(wir_r, van, sut, p_gen), q_gen);
      }

      case c3__csbn: 
      {
        return _play_flag(wir_r);
      }
      case c3__csdg: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      {
        u2_noun fex = j2_mcy(Pit, ut, gain)(wir_r, van, sut, p_gen);

        if ( c3__void == fex ) {
          return _play_in(wir_r, van, sut, r_gen);
        } else {
          return j2_mby(Pit, fork)
            (wir_r, _play_in(wir_r, van, fex, q_gen),
                    _play_in(wir_r, van, sut, r_gen));
        }
      }
      case c3__dgdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return j2_mby(Pit, cell)
          (wir_r, _play_in(wir_r, van, fex, q_gen),
                  _play_in(wir_r, van, sut, r_gen));
      }
      case c3__dtbn: 
      {
        return _play_flag(wir_r);
      }
      case c3__dtcs:
      {
        return _play_flag(wir_r);
      }
      case c3__dtkt: 
      {
        return c3__atom;
      }
      case c3__dttg: p_gen = u2_t(gen);
      {
        return u2_bc(wir_r, c3__cube, u2_rx(wir_r, p_gen));
      }
      case c3__dttr:
      {
        return c3__noun;
      }
      case c3__ktbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return 
           u2_bt(wir_r, c3__face,
                        u2_rx(wir_r, p_gen), 
                        _play_in(wir_r, van, sut, q_gen));
      }
      case c3__ktdp: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return _play_in(wir_r, van, sut, p_gen);
      }
      case c3__ktpd: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return _play_in(wir_r, van, sut, q_gen);
      }
      case c3__kttg: p_gen = u2_t(gen);
      {
        return _play_in(wir_r, van, sut, p_gen);
      }
      case c3__mtbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun lar = j2_mcy(Pit, ut, seek)(wir_r, van, sut, c3__read, p_gen);
        u2_noun p_lar, q_lar, r_lar;

        u2_bi_trel(wir_r, lar, &p_lar, &q_lar, &r_lar);
        {
          u2_noun wix = j2_mcy(Pit, ut, edit)
              (wir_r, van, sut, p_lar, r_lar, q_gen);

          if ( u2_nul == q_lar ) {
            u2_rl_lose(wir_r, lar);
            return wix;
          } else {
            u2_noun ret = j2_mcy(Pit, ut, fire)
              (wir_r, van, wix, u2_t(u2_t(q_lar)));

            u2_rl_lose(wir_r, wix);
            u2_rl_lose(wir_r, lar);
            return ret;
          }
        }
      }
      case c3__pmbn: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        u2_noun dim = _play_in(wir_r, van, sut, p_gen);
        u2_noun gur = j2_mby(Pit, cell)(wir_r, dim, sut);
        u2_noun zun = u2_bc(wir_r, u2_bc(wir_r, 0, 0), u2_rx(wir_r, q_gen));
        u2_noun con = u2_bt(wir_r, c3__lead, u2_rx(wir_r, gur), zun);
        u2_noun ret = j2_mby(Pit, core)(wir_r, gur, con);

        u2_rz(wir_r, dim);
        u2_rz(wir_r, gur);
        u2_rz(wir_r, con);

        return ret;
      }
      case c3__pmdg: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      { 
        u2_noun dim = _play_in(wir_r, van, sut, p_gen);
        u2_noun gur = j2_mby(Pit, cell)(wir_r, dim, sut);
        u2_noun zun = u2_bc(wir_r, u2_bc(wir_r, 0, 0), u2_rx(wir_r, q_gen));
        u2_noun con = u2_bt(wir_r, c3__iron, u2_rx(wir_r, gur), zun);
        u2_noun ret = j2_mby(Pit, core)(wir_r, gur, con);

        u2_rz(wir_r, dim);
        u2_rz(wir_r, gur);
        u2_rz(wir_r, con);

        return ret;
      }
      case c3__pmdt: p_gen = u2_t(gen);
      {
        u2_noun con = u2_bt(wir_r, c3__gold, u2_rx(wir_r, sut), zun);
        u2_noun ret = j2_mby(Pit, core)(wir_r, sut, con);

        u2_rz(wir_r, con);
        return ret;
      }
      case c3__pmmt: u2_bi_trel(wir_r, u2_t(gen), &p_gen, &q_gen, &r_gen);
      {
        u2_noun dim = _play_in(wir_r, van, sut, p_gen);
        u2_noun hen = _play_in(wir_r, van, sut, q_gen);
        u2_noun sib = j2_mby(Pit, cell)(wir_r, hen, sut);
        u2_noun gur = j2_mby(Pit, cell)(wir_r, dim, sib);
        u2_noun zun = u2_bc(wir_r, u2_bc(wir_r, 0, 0), u2_rx(wir_r, q_gen));
        u2_noun con = u2_bt(wir_r, c3__zinc, u2_rx(wir_r, gur), zun);
        u2_noun ret = j2_mby(Pit, core)(wir_r, gur, con);

        u2_rz(wir_r, dim);
        u2_rz(wir_r, hen);
        u2_rz(wir_r, sib);
        u2_rz(wir_r, gur);
        u2_rz(wir_r, con);

        return ret;
      }
      case c3__pmtr: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      { 
        u2_noun dim = _play_in(wir_r, van, sut, p_gen);
        u2_noun gur = j2_mby(Pit, cell)(wir_r, dim, sut);
        u2_noun zun = u2_bc(wir_r, u2_bc(wir_r, 0, 0), u2_rx(wir_r, q_gen));
        u2_noun con = u2_bt(wir_r, c3__wood, u2_rx(wir_r, gur), zun);
        u2_noun ret = j2_mby(Pit, core)(wir_r, gur, con);

        u2_rz(wir_r, dim);
        u2_rz(wir_r, gur);
        u2_rz(wir_r, con);

        return ret;
      }
      case c3__tgld: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return _play_in(wir_r, van, sut, q_gen);
      }
      case c3__zpbn: p_gen = u2_t(gen);
      {
        return c3__noun;
      }
      case c3__zpcb: u2_bi_cell(wir_r, u2_t(gen), &p_gen, &q_gen);
      {
        return _play_in(wir_r, van, sut, q_gen);
      }
      case c3__zpdx: p_gen = u2_t(gen);
      {
        return _play_in(wir_r, van, sut, p_gen);
      }
      case c3__zpzp:
      {
        return c3__void;
      }
    }
  }

  u2_noun                                                         //  transfer
  j2_mcx(Pit, ut, play)(u2_wire wir_r, 
                          u2_noun van,                            //  retain
                          u2_noun sut,                            //  retain
                          u2_noun gen)                            //  retain
  {
    u2_noun von = u2_bn_cook(wir_r, van, "vet", u2_no);
    u2_noun ret = _play_in(wir_r, von, sut, gen);

    u2_rl_lose(wir_r, von);
    return ret;
  }

/* boilerplate
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, play)[];

  u2_noun                                                         //  transfer
  j2_mc(Pit, ut, play)(u2_wire wir_r, 
                         u2_noun cor)                             //  retain
  {
    u2_noun sut, gen, van;

    if ( (u2_no == u2_mean(cor, u2_cv_sam, &gen, u2_cv_con, &van, 0)) ||
         (u2_none == (sut = u2_frag(u2_cv_sam, van))) )
    {
      return u2_bl_bail(wir_r);
    } else {
      return j2_mcx(Pit, ut, play)(wir_r, van, sut, gen);
    }
  }

  u2_weak                                                         //  transfer
  j2_mci(Pit, ut, play)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain 
                        u2_noun gen)                              //  retain
  {
    u2_weak hoc = u2_sh_look(wir_r, van, "play");

    if ( u2_none == hoc ) {
      c3_assert(!"register play");
      return u2_none;
    } else {
      u2_weak von = u2_rl_molt(wir_r, van, u2_cv_sam, u2_rx(wir_r, sut), 0);
      u2_weak gat = u2_nk_soft(wir_r, von, hoc);
      u2_weak cor = u2_rl_molt(wir_r, gat, u2_cv_sam, u2_rx(wir_r, gen), 0);

      if ( (u2_none == j2_mcj(Pit, ut, play)[0].xip) ) {
        u2_noun xip = u2_sh_find(wir_r, cor);
     
        c3_assert(u2_none != xip);
        j2_mcj(Pit, ut, play)[0].xip = xip;
      }
      u2_rl_lose(wir_r, gat);
      return cor;
    }
  }

  u2_noun                                                         //  transfer
  j2_mcy(Pit, ut, play)(u2_wire wir_r,
                        u2_noun van,                              //  retain
                        u2_noun sut,                              //  retain
                        u2_noun gen)                              //  retain
  {
    u2_ho_jet *jet_j = &j2_mcj(Pit, ut, play)[0];

    switch ( jet_j->sat_s ) {
      default: c3_assert(0); return u2_bl_bail(wir_r);

      case u2_jet_live: {
        return j2_mcx(Pit, ut, play)(wir_r, van, sut, gen);
      }
      case u2_jet_dead: {
        u2_noun cor, sof;

        cor = j2_mci(Pit, ut, play)(wir_r, van, sut, gen);
        sof = u2_nk_soft(wir_r, cor, u2_frag(u2_cv_noc, cor));

        return u2_bl_good(wir_r, sof);
      }
      case u2_jet_limp: {
        u2_weak had, cor, sof;

        /* Compute `had`, the C version.  Jet is full-on recursive.
        ** Catch bails.
        */
        {
          jet_j->sat_s = u2_jet_live;
          {
            u2_ray jub_r = u2_bl_open(wir_r);

            if ( u2_bl_set(wir_r) ) {
              u2_bl_done(wir_r, jub_r);
              had = u2_none;
            } 
            else {
              had = j2_mcx(Pit, ut, play)(wir_r, van, sut, gen);
              u2_bl_done(wir_r, jub_r);
            }
          }
          jet_j->sat_s = u2_jet_limp;
        }

        /* Compute `sof`, the Nock version.  Jet is full-off recursively.
        */
        {
          jet_j->sat_s = u2_jet_dead;
          {
            cor = j2_mci(Pit, ut, play)(wir_r, van, sut, gen);
            sof = u2_nk_soft(wir_r, u2_rx(wir_r, cor), 
                                    u2_frag(u2_cv_noc, cor));
          }
          jet_j->sat_s = u2_jet_limp;
        }
        u2_ho_test(jet_j, cor, sof, had);
        u2_rl_lose(wir_r, cor);

        if ( u2_none == sof ) {
          return had;
        } else {
          u2_rl_lose(wir_r, had);
          return sof;
        }
      }
    }
  }

/* structures
*/
  u2_ho_jet 
  j2_mcj(Pit, ut, play)[] = {
    { ".3", c3__hevy, j2_mc(Pit, ut, play), SafeTier6, u2_none, u2_none },
    { }
  };
