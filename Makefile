# A simple makefile.
#

# Pick one of:
#   linux
#   osx
#
#OS=linux
OS=osx

# Pick one of:
#   little
#   big
#
ENDIAN=little

# Binary directory - not in quotes.
#
BIN=bin

RM=rm -f
CC=gcc
CLD=gcc -O3 -L/usr/local/lib
YACC=bison -v -b$(GENERATED)/y
LEX=lex

INCLUDE=include
GENERATED=generated
DEFINES=-DU2_OS_$(OS) -DU2_OS_ENDIAN_$(ENDIAN)
CFLAGS=-O3 -I/usr/local/include -I$(INCLUDE) -I $(GENERATED) $(DEFINES)
CWFLAGS=-Wall

.y.o:
	 mkdir -p $(GENERATED)
	 $(YACC) $<
	 $(CC) -c $(CFLAGS) -o $@ $(GENERATED)/y.tab.c
	 $(RM) $(GENERATED)/y.tab.c

.c.o:
	 $(CC) -c $(CWFLAGS) $(CFLAGS) -o $@ $<

C_OFILES=\
       c/comd.o

F_OFILES=\
       f/rail.o \
       f/loom.o \
       f/wire.o \
       f/chad.o \
       f/cash.o \
       f/coal.o \
       f/hevn.o \
       f/host.o \
       f/benx.o \
       f/trac.o \
       f/bail.o \
       f/dash.o \
       f/unix.o \
       f/nock.o

P_OFILES=\
       p/book.o \
       p/list.o \
       p/pool.o \
       p/prep.o \
       p/saur.o

J225_1_OFILES=\
       gen225/1/add.o \
       gen225/1/dec.o \
       gen225/1/div.o \
       gen225/1/gte.o \
       gen225/1/gth.o \
       gen225/1/lte.o \
       gen225/1/lth.o \
       gen225/1/mod.o \
       gen225/1/mul.o \
       gen225/1/sub.o

J225_2_OFILES=\
       gen225/2/bind.o \
       gen225/2/clap.o \
       gen225/2/drop.o \
       gen225/2/flop.o \
       gen225/2/lent.o \
       gen225/2/levy.o \
       gen225/2/lien.o \
       gen225/2/need.o \
       gen225/2/reel.o \
       gen225/2/roll.o \
       gen225/2/skim.o \
       gen225/2/skip.o \
       gen225/2/slag.o \
       gen225/2/snag.o \
       gen225/2/sort.o \
       gen225/2/turn.o \
       gen225/2/weld.o

J225_3_OFILES=\
       gen225/3/bex.o \
       gen225/3/can.o \
       gen225/3/cap.o \
       gen225/3/cat.o \
       gen225/3/con.o \
       gen225/3/cut.o \
       gen225/3/dor.o \
       gen225/3/dis.o \
       gen225/3/end.o \
       gen225/3/gor.o \
       gen225/3/hor.o \
       gen225/3/lsh.o \
       gen225/3/mas.o \
       gen225/3/met.o \
       gen225/3/mix.o \
       gen225/3/mug.o \
       gen225/3/peg.o \
       gen225/3/rap.o \
       gen225/3/rip.o \
       gen225/3/rsh.o \
       gen225/3/vor.o

J225_4_OFILES=\
       gen225/4/in.o \
       gen225/4/by.o \
       gen225/4/in_has.o \
       gen225/4/in_gas.o \
       gen225/4/in_put.o \
       gen225/4/in_tap.o \
       gen225/4/by_gas.o \
       gen225/4/by_get.o \
       gen225/4/by_has.o \
       gen225/4/by_put.o 

J225_5_OFILES=\
       gen225/5/cue.o \
       gen225/5/jam.o \
       gen225/5/mat.o \
       gen225/5/parse.o \
       gen225/5/rub.o \
       gen225/5/shax.o \
       gen225/5/trip.o

J225_6_OFILES=\
       gen225/6/ap.o \
       gen225/6/cell.o \
       gen225/6/comb.o \
       gen225/6/cons.o \
       gen225/6/core.o \
       gen225/6/cube.o \
       gen225/6/face.o \
       gen225/6/fine.o \
       gen225/6/flan.o \
       gen225/6/flip.o \
       gen225/6/flor.o \
       gen225/6/foam.o \
       gen225/6/fork.o \
       gen225/6/hike.o \
       gen225/6/look.o \
       gen225/6/ut.o

J225_6_OFILES_UT=\
       gen225/6/ut_burn.o \
       gen225/6/ut_bust.o \
       gen225/6/ut_crop.o \
       gen225/6/ut_cull.o \
       gen225/6/ut_find.o \
       gen225/6/ut_fink.o \
       gen225/6/ut_fire.o \
       gen225/6/ut_firm.o \
       gen225/6/ut_fish.o \
       gen225/6/ut_fuse.o \
       gen225/6/ut_gain.o \
       gen225/6/ut_heal.o \
       gen225/6/ut_lose.o \
       gen225/6/ut_mint.o \
       gen225/6/ut_moot.o \
       gen225/6/ut_mull.o \
       gen225/6/ut_nest.o \
       gen225/6/ut_park.o \
       gen225/6/ut_peek.o \
       gen225/6/ut_play.o \
       gen225/6/ut_repo.o \
       gen225/6/ut_rest.o \
       gen225/6/ut_seek.o \
       gen225/6/ut_snap.o \
       gen225/6/ut_swab.o \
       gen225/6/ut_tack.o \
       gen225/6/ut_tock.o

J225_OFILES=\
       $(J225_1_OFILES) \
       $(J225_2_OFILES) \
       $(J225_3_OFILES) \
       $(J225_4_OFILES) \
       $(J225_5_OFILES) \
       $(J225_6_OFILES) \
       $(J225_6_OFILES_UT) \
       gen225/watt.o

J224_1_OFILES=\
       gen224/1/add.o \
       gen224/1/dec.o \
       gen224/1/div.o \
       gen224/1/gte.o \
       gen224/1/gth.o \
       gen224/1/lte.o \
       gen224/1/lth.o \
       gen224/1/mod.o \
       gen224/1/mul.o \
       gen224/1/sub.o

J224_2_OFILES=\
       gen224/2/bind.o \
       gen224/2/clap.o \
       gen224/2/drop.o \
       gen224/2/flop.o \
       gen224/2/lent.o \
       gen224/2/levy.o \
       gen224/2/lien.o \
       gen224/2/need.o \
       gen224/2/reel.o \
       gen224/2/roll.o \
       gen224/2/skim.o \
       gen224/2/skip.o \
       gen224/2/slag.o \
       gen224/2/snag.o \
       gen224/2/sort.o \
       gen224/2/turn.o \
       gen224/2/weld.o

J224_3_OFILES=\
       gen224/3/bex.o \
       gen224/3/can.o \
       gen224/3/cap.o \
       gen224/3/cat.o \
       gen224/3/con.o \
       gen224/3/cut.o \
       gen224/3/dor.o \
       gen224/3/dis.o \
       gen224/3/end.o \
       gen224/3/gor.o \
       gen224/3/hor.o \
       gen224/3/lsh.o \
       gen224/3/mas.o \
       gen224/3/met.o \
       gen224/3/mix.o \
       gen224/3/mug.o \
       gen224/3/peg.o \
       gen224/3/rap.o \
       gen224/3/rip.o \
       gen224/3/rsh.o \
       gen224/3/vor.o

J224_4_OFILES=\
       gen224/4/in.o \
       gen224/4/by.o \
       gen224/4/in_has.o \
       gen224/4/in_gas.o \
       gen224/4/in_put.o \
       gen224/4/in_tap.o \
       gen224/4/by_gas.o \
       gen224/4/by_get.o \
       gen224/4/by_has.o \
       gen224/4/by_put.o 

J224_5_OFILES=\
       gen224/5/cue.o \
       gen224/5/jam.o \
       gen224/5/mat.o \
       gen224/5/parse.o \
       gen224/5/rub.o \
       gen224/5/shax.o \
       gen224/5/trip.o

J224_6_OFILES=\
       gen224/6/ap.o \
       gen224/6/cell.o \
       gen224/6/comb.o \
       gen224/6/cons.o \
       gen224/6/core.o \
       gen224/6/cube.o \
       gen224/6/face.o \
       gen224/6/fine.o \
       gen224/6/flan.o \
       gen224/6/flip.o \
       gen224/6/flor.o \
       gen224/6/foam.o \
       gen224/6/fork.o \
       gen224/6/hike.o \
       gen224/6/look.o \
       gen224/6/ut.o

J224_6_OFILES_UT=\
       gen224/6/ut_burn.o \
       gen224/6/ut_bust.o \
       gen224/6/ut_crop.o \
       gen224/6/ut_cull.o \
       gen224/6/ut_find.o \
       gen224/6/ut_fink.o \
       gen224/6/ut_fire.o \
       gen224/6/ut_firm.o \
       gen224/6/ut_fish.o \
       gen224/6/ut_fuse.o \
       gen224/6/ut_gain.o \
       gen224/6/ut_heal.o \
       gen224/6/ut_lose.o \
       gen224/6/ut_mint.o \
       gen224/6/ut_moot.o \
       gen224/6/ut_mull.o \
       gen224/6/ut_nest.o \
       gen224/6/ut_park.o \
       gen224/6/ut_peek.o \
       gen224/6/ut_play.o \
       gen224/6/ut_repo.o \
       gen224/6/ut_rest.o \
       gen224/6/ut_seek.o \
       gen224/6/ut_snap.o \
       gen224/6/ut_swab.o \
       gen224/6/ut_tack.o \
       gen224/6/ut_tock.o \
       gen224/6/ut_wrap.o

J224_OFILES=\
       $(J224_1_OFILES) \
       $(J224_2_OFILES) \
       $(J224_3_OFILES) \
       $(J224_4_OFILES) \
       $(J224_5_OFILES) \
       $(J224_6_OFILES) \
       $(J224_6_OFILES_UT) \
       gen224/watt.o

J223_1_OFILES=\
       gen223/1/add.o \
       gen223/1/dec.o \
       gen223/1/div.o \
       gen223/1/gte.o \
       gen223/1/gth.o \
       gen223/1/lte.o \
       gen223/1/lth.o \
       gen223/1/mod.o \
       gen223/1/mul.o \
       gen223/1/sub.o

J223_2_OFILES=\
       gen223/2/bind.o \
       gen223/2/clap.o \
       gen223/2/drop.o \
       gen223/2/flop.o \
       gen223/2/lent.o \
       gen223/2/levy.o \
       gen223/2/lien.o \
       gen223/2/need.o \
       gen223/2/reel.o \
       gen223/2/roll.o \
       gen223/2/skim.o \
       gen223/2/skip.o \
       gen223/2/slag.o \
       gen223/2/snag.o \
       gen223/2/sort.o \
       gen223/2/turn.o \
       gen223/2/weld.o

J223_3_OFILES=\
       gen223/3/bex.o \
       gen223/3/can.o \
       gen223/3/cap.o \
       gen223/3/cat.o \
       gen223/3/con.o \
       gen223/3/cut.o \
       gen223/3/dor.o \
       gen223/3/dis.o \
       gen223/3/end.o \
       gen223/3/gor.o \
       gen223/3/hor.o \
       gen223/3/lsh.o \
       gen223/3/mas.o \
       gen223/3/met.o \
       gen223/3/mix.o \
       gen223/3/mug.o \
       gen223/3/peg.o \
       gen223/3/rap.o \
       gen223/3/rip.o \
       gen223/3/rsh.o \
       gen223/3/vor.o

J223_4_OFILES=\
       gen223/4/in.o \
       gen223/4/by.o \
       gen223/4/in_has.o \
       gen223/4/in_gas.o \
       gen223/4/in_put.o \
       gen223/4/in_tap.o \
       gen223/4/by_gas.o \
       gen223/4/by_get.o \
       gen223/4/by_has.o \
       gen223/4/by_put.o 

J223_5_OFILES=\
       gen223/5/cue.o \
       gen223/5/jam.o \
       gen223/5/mat.o \
       gen223/5/parse.o \
       gen223/5/rub.o \
       gen223/5/shax.o \
       gen223/5/trip.o

J223_6_OFILES=\
       gen223/6/ap.o \
       gen223/6/cell.o \
       gen223/6/comb.o \
       gen223/6/cons.o \
       gen223/6/core.o \
       gen223/6/cube.o \
       gen223/6/face.o \
       gen223/6/fine.o \
       gen223/6/flan.o \
       gen223/6/flip.o \
       gen223/6/flor.o \
       gen223/6/foam.o \
       gen223/6/fork.o \
       gen223/6/hike.o \
       gen223/6/look.o \
       gen223/6/ut.o

J223_6_OFILES_UT=\
       gen223/6/ut_burn.o \
       gen223/6/ut_bust.o \
       gen223/6/ut_crop.o \
       gen223/6/ut_cull.o \
       gen223/6/ut_find.o \
       gen223/6/ut_fink.o \
       gen223/6/ut_fire.o \
       gen223/6/ut_firm.o \
       gen223/6/ut_fish.o \
       gen223/6/ut_fuse.o \
       gen223/6/ut_gain.o \
       gen223/6/ut_heal.o \
       gen223/6/ut_lose.o \
       gen223/6/ut_mint.o \
       gen223/6/ut_moot.o \
       gen223/6/ut_mull.o \
       gen223/6/ut_nest.o \
       gen223/6/ut_park.o \
       gen223/6/ut_peek.o \
       gen223/6/ut_play.o \
       gen223/6/ut_repo.o \
       gen223/6/ut_rest.o \
       gen223/6/ut_seek.o \
       gen223/6/ut_snap.o \
       gen223/6/ut_swab.o \
       gen223/6/ut_tack.o \
       gen223/6/ut_tock.o \
       gen223/6/ut_wrap.o

J223_OFILES=\
       $(J223_1_OFILES) \
       $(J223_2_OFILES) \
       $(J223_3_OFILES) \
       $(J223_4_OFILES) \
       $(J223_5_OFILES) \
       $(J223_6_OFILES) \
       $(J223_6_OFILES_UT) \
       gen223/watt.o

J222_1_OFILES=\
       gen222/1/add.o \
       gen222/1/dec.o \
       gen222/1/div.o \
       gen222/1/gte.o \
       gen222/1/gth.o \
       gen222/1/lte.o \
       gen222/1/lth.o \
       gen222/1/mod.o \
       gen222/1/mul.o \
       gen222/1/sub.o

J222_2_OFILES=\
       gen222/2/bind.o \
       gen222/2/clap.o \
       gen222/2/drop.o \
       gen222/2/flop.o \
       gen222/2/lent.o \
       gen222/2/levy.o \
       gen222/2/lien.o \
       gen222/2/need.o \
       gen222/2/reel.o \
       gen222/2/roll.o \
       gen222/2/skim.o \
       gen222/2/skip.o \
       gen222/2/slag.o \
       gen222/2/snag.o \
       gen222/2/sort.o \
       gen222/2/turn.o \
       gen222/2/weld.o

J222_3_OFILES=\
       gen222/3/bex.o \
       gen222/3/can.o \
       gen222/3/cap.o \
       gen222/3/cat.o \
       gen222/3/con.o \
       gen222/3/cut.o \
       gen222/3/dor.o \
       gen222/3/dis.o \
       gen222/3/end.o \
       gen222/3/gor.o \
       gen222/3/hor.o \
       gen222/3/lsh.o \
       gen222/3/mas.o \
       gen222/3/met.o \
       gen222/3/mix.o \
       gen222/3/mug.o \
       gen222/3/peg.o \
       gen222/3/rap.o \
       gen222/3/rip.o \
       gen222/3/rsh.o \
       gen222/3/vor.o

J222_4_OFILES=\
       gen222/4/in.o \
       gen222/4/by.o \
       gen222/4/in_has.o \
       gen222/4/in_gas.o \
       gen222/4/in_put.o \
       gen222/4/in_tap.o \
       gen222/4/by_gas.o \
       gen222/4/by_get.o \
       gen222/4/by_has.o \
       gen222/4/by_put.o 

J222_5_OFILES=\
       gen222/5/cue.o \
       gen222/5/jam.o \
       gen222/5/mat.o \
       gen222/5/parse.o \
       gen222/5/rub.o \
       gen222/5/shax.o \
       gen222/5/trip.o

J222_6_OFILES=\
       gen222/6/ap.o \
       gen222/6/cell.o \
       gen222/6/comb.o \
       gen222/6/cons.o \
       gen222/6/core.o \
       gen222/6/cube.o \
       gen222/6/face.o \
       gen222/6/fine.o \
       gen222/6/flan.o \
       gen222/6/flip.o \
       gen222/6/flor.o \
       gen222/6/foam.o \
       gen222/6/fork.o \
       gen222/6/hike.o \
       gen222/6/look.o \
       gen222/6/ut.o

J222_6_OFILES_UT=\
       gen222/6/ut_burn.o \
       gen222/6/ut_bust.o \
       gen222/6/ut_crop.o \
       gen222/6/ut_cull.o \
       gen222/6/ut_find.o \
       gen222/6/ut_fink.o \
       gen222/6/ut_fire.o \
       gen222/6/ut_firm.o \
       gen222/6/ut_fish.o \
       gen222/6/ut_fuse.o \
       gen222/6/ut_gain.o \
       gen222/6/ut_heal.o \
       gen222/6/ut_lose.o \
       gen222/6/ut_mint.o \
       gen222/6/ut_moot.o \
       gen222/6/ut_mull.o \
       gen222/6/ut_nest.o \
       gen222/6/ut_park.o \
       gen222/6/ut_peek.o \
       gen222/6/ut_play.o \
       gen222/6/ut_repo.o \
       gen222/6/ut_rest.o \
       gen222/6/ut_seek.o \
       gen222/6/ut_snap.o \
       gen222/6/ut_swab.o \
       gen222/6/ut_tack.o \
       gen222/6/ut_tock.o \
       gen222/6/ut_wrap.o

J222_OFILES=\
       $(J222_1_OFILES) \
       $(J222_2_OFILES) \
       $(J222_3_OFILES) \
       $(J222_4_OFILES) \
       $(J222_5_OFILES) \
       $(J222_6_OFILES) \
       $(J222_6_OFILES_UT) \
       gen222/watt.o

J221_1_OFILES=\
       gen221/1/add.o \
       gen221/1/dec.o \
       gen221/1/div.o \
       gen221/1/gte.o \
       gen221/1/gth.o \
       gen221/1/lte.o \
       gen221/1/lth.o \
       gen221/1/mod.o \
       gen221/1/mul.o \
       gen221/1/sub.o

J221_2_OFILES=\
       gen221/2/bind.o \
       gen221/2/clap.o \
       gen221/2/drop.o \
       gen221/2/flop.o \
       gen221/2/lent.o \
       gen221/2/levy.o \
       gen221/2/lien.o \
       gen221/2/need.o \
       gen221/2/reel.o \
       gen221/2/roll.o \
       gen221/2/skim.o \
       gen221/2/skip.o \
       gen221/2/slag.o \
       gen221/2/snag.o \
       gen221/2/sort.o \
       gen221/2/turn.o \
       gen221/2/weld.o

J221_3_OFILES=\
       gen221/3/bex.o \
       gen221/3/can.o \
       gen221/3/cap.o \
       gen221/3/cat.o \
       gen221/3/con.o \
       gen221/3/cut.o \
       gen221/3/dor.o \
       gen221/3/dis.o \
       gen221/3/end.o \
       gen221/3/gor.o \
       gen221/3/hor.o \
       gen221/3/lsh.o \
       gen221/3/mas.o \
       gen221/3/met.o \
       gen221/3/mix.o \
       gen221/3/mug.o \
       gen221/3/peg.o \
       gen221/3/rap.o \
       gen221/3/rip.o \
       gen221/3/rsh.o \
       gen221/3/vor.o

J221_4_OFILES=\
       gen221/4/in.o \
       gen221/4/by.o \
       gen221/4/in_has.o \
       gen221/4/in_gas.o \
       gen221/4/in_put.o \
       gen221/4/in_tap.o \
       gen221/4/by_gas.o \
       gen221/4/by_get.o \
       gen221/4/by_has.o \
       gen221/4/by_put.o 

J221_5_OFILES=\
       gen221/5/cue.o \
       gen221/5/jam.o \
       gen221/5/mat.o \
       gen221/5/parse.o \
       gen221/5/rub.o \
       gen221/5/shax.o \
       gen221/5/trip.o

J221_6_OFILES=\
       gen221/6/ap.o \
       gen221/6/cell.o \
       gen221/6/comb.o \
       gen221/6/cons.o \
       gen221/6/core.o \
       gen221/6/cube.o \
       gen221/6/face.o \
       gen221/6/fine.o \
       gen221/6/flan.o \
       gen221/6/flip.o \
       gen221/6/flor.o \
       gen221/6/foam.o \
       gen221/6/fork.o \
       gen221/6/hike.o \
       gen221/6/look.o \
       gen221/6/ut.o

J221_6_OFILES_UT=\
       gen221/6/ut_burn.o \
       gen221/6/ut_bust.o \
       gen221/6/ut_crop.o \
       gen221/6/ut_cull.o \
       gen221/6/ut_find.o \
       gen221/6/ut_fink.o \
       gen221/6/ut_fire.o \
       gen221/6/ut_firm.o \
       gen221/6/ut_fish.o \
       gen221/6/ut_fuse.o \
       gen221/6/ut_gain.o \
       gen221/6/ut_heal.o \
       gen221/6/ut_lose.o \
       gen221/6/ut_mint.o \
       gen221/6/ut_moot.o \
       gen221/6/ut_mull.o \
       gen221/6/ut_nest.o \
       gen221/6/ut_park.o \
       gen221/6/ut_peek.o \
       gen221/6/ut_play.o \
       gen221/6/ut_repo.o \
       gen221/6/ut_rest.o \
       gen221/6/ut_seek.o \
       gen221/6/ut_snap.o \
       gen221/6/ut_swab.o \
       gen221/6/ut_tack.o \
       gen221/6/ut_tock.o \
       gen221/6/ut_wrap.o

J221_OFILES=\
       $(J221_1_OFILES) \
       $(J221_2_OFILES) \
       $(J221_3_OFILES) \
       $(J221_4_OFILES) \
       $(J221_5_OFILES) \
       $(J221_6_OFILES) \
       $(J221_6_OFILES_UT) \
       gen221/watt.o

J220_1_OFILES=\
       gen220/1/add.o \
       gen220/1/dec.o \
       gen220/1/div.o \
       gen220/1/gte.o \
       gen220/1/gth.o \
       gen220/1/lte.o \
       gen220/1/lth.o \
       gen220/1/mod.o \
       gen220/1/mul.o \
       gen220/1/sub.o

J220_2_OFILES=\
       gen220/2/bind.o \
       gen220/2/clap.o \
       gen220/2/drop.o \
       gen220/2/flop.o \
       gen220/2/lent.o \
       gen220/2/levy.o \
       gen220/2/lien.o \
       gen220/2/need.o \
       gen220/2/reel.o \
       gen220/2/roll.o \
       gen220/2/skim.o \
       gen220/2/skip.o \
       gen220/2/slag.o \
       gen220/2/snag.o \
       gen220/2/sort.o \
       gen220/2/turn.o \
       gen220/2/weld.o

J220_3_OFILES=\
       gen220/3/bex.o \
       gen220/3/can.o \
       gen220/3/cap.o \
       gen220/3/cat.o \
       gen220/3/con.o \
       gen220/3/cut.o \
       gen220/3/dor.o \
       gen220/3/dis.o \
       gen220/3/end.o \
       gen220/3/gor.o \
       gen220/3/hor.o \
       gen220/3/lsh.o \
       gen220/3/mas.o \
       gen220/3/met.o \
       gen220/3/mix.o \
       gen220/3/mug.o \
       gen220/3/peg.o \
       gen220/3/rap.o \
       gen220/3/rip.o \
       gen220/3/rsh.o \
       gen220/3/vor.o

J220_4_OFILES=\
       gen220/4/in.o \
       gen220/4/by.o \
       gen220/4/in_has.o \
       gen220/4/in_gas.o \
       gen220/4/in_put.o \
       gen220/4/in_tap.o \
       gen220/4/by_gas.o \
       gen220/4/by_get.o \
       gen220/4/by_has.o \
       gen220/4/by_put.o 

J220_5_OFILES=\
       gen220/5/cue.o \
       gen220/5/jam.o \
       gen220/5/mat.o \
       gen220/5/parse.o \
       gen220/5/rub.o \
       gen220/5/shax.o \
       gen220/5/trip.o

J220_6_OFILES=\
       gen220/6/ap.o \
       gen220/6/cell.o \
       gen220/6/comb.o \
       gen220/6/cons.o \
       gen220/6/core.o \
       gen220/6/cube.o \
       gen220/6/face.o \
       gen220/6/fine.o \
       gen220/6/flan.o \
       gen220/6/flip.o \
       gen220/6/flor.o \
       gen220/6/foam.o \
       gen220/6/fork.o \
       gen220/6/hike.o \
       gen220/6/look.o \
       gen220/6/ut.o

J220_6_OFILES_UT=\
       gen220/6/ut_burn.o \
       gen220/6/ut_bust.o \
       gen220/6/ut_crop.o \
       gen220/6/ut_cull.o \
       gen220/6/ut_find.o \
       gen220/6/ut_fink.o \
       gen220/6/ut_fire.o \
       gen220/6/ut_firm.o \
       gen220/6/ut_fish.o \
       gen220/6/ut_fuse.o \
       gen220/6/ut_gain.o \
       gen220/6/ut_heal.o \
       gen220/6/ut_lose.o \
       gen220/6/ut_mint.o \
       gen220/6/ut_moot.o \
       gen220/6/ut_mull.o \
       gen220/6/ut_nest.o \
       gen220/6/ut_park.o \
       gen220/6/ut_peek.o \
       gen220/6/ut_play.o \
       gen220/6/ut_repo.o \
       gen220/6/ut_rest.o \
       gen220/6/ut_seek.o \
       gen220/6/ut_snap.o \
       gen220/6/ut_swab.o \
       gen220/6/ut_tack.o \
       gen220/6/ut_tock.o \
       gen220/6/ut_wrap.o

J220_OFILES=\
       $(J220_1_OFILES) \
       $(J220_2_OFILES) \
       $(J220_3_OFILES) \
       $(J220_4_OFILES) \
       $(J220_5_OFILES) \
       $(J220_6_OFILES) \
       $(J220_6_OFILES_UT) \
       gen220/watt.o

J219_1_OFILES=\
       gen219/1/add.o \
       gen219/1/dec.o \
       gen219/1/div.o \
       gen219/1/gte.o \
       gen219/1/gth.o \
       gen219/1/lte.o \
       gen219/1/lth.o \
       gen219/1/mod.o \
       gen219/1/mul.o \
       gen219/1/sub.o

J219_2_OFILES=\
       gen219/2/bind.o \
       gen219/2/clap.o \
       gen219/2/drop.o \
       gen219/2/flop.o \
       gen219/2/lent.o \
       gen219/2/levy.o \
       gen219/2/lien.o \
       gen219/2/need.o \
       gen219/2/reel.o \
       gen219/2/roll.o \
       gen219/2/skim.o \
       gen219/2/skip.o \
       gen219/2/slag.o \
       gen219/2/snag.o \
       gen219/2/sort.o \
       gen219/2/turn.o \
       gen219/2/weld.o

J219_3_OFILES=\
       gen219/3/bex.o \
       gen219/3/can.o \
       gen219/3/cap.o \
       gen219/3/cat.o \
       gen219/3/con.o \
       gen219/3/cut.o \
       gen219/3/dor.o \
       gen219/3/dis.o \
       gen219/3/end.o \
       gen219/3/gor.o \
       gen219/3/hor.o \
       gen219/3/lsh.o \
       gen219/3/mas.o \
       gen219/3/met.o \
       gen219/3/mix.o \
       gen219/3/mug.o \
       gen219/3/peg.o \
       gen219/3/rap.o \
       gen219/3/rip.o \
       gen219/3/rsh.o \
       gen219/3/vor.o

J219_4_OFILES=\
       gen219/4/in.o \
       gen219/4/by.o \
       gen219/4/in_has.o \
       gen219/4/in_gas.o \
       gen219/4/in_put.o \
       gen219/4/in_tap.o \
       gen219/4/by_gas.o \
       gen219/4/by_get.o \
       gen219/4/by_has.o \
       gen219/4/by_put.o 

J219_5_OFILES=\
       gen219/5/cue.o \
       gen219/5/jam.o \
       gen219/5/mat.o \
       gen219/5/parse.o \
       gen219/5/rub.o \
       gen219/5/shax.o \
       gen219/5/trip.o

J219_6_OFILES=\
       gen219/6/ap.o \
       gen219/6/cell.o \
       gen219/6/comb.o \
       gen219/6/cons.o \
       gen219/6/core.o \
       gen219/6/cube.o \
       gen219/6/face.o \
       gen219/6/fine.o \
       gen219/6/flan.o \
       gen219/6/flip.o \
       gen219/6/flor.o \
       gen219/6/foam.o \
       gen219/6/fork.o \
       gen219/6/hike.o \
       gen219/6/look.o \
       gen219/6/ut.o

J219_6_OFILES_UT=\
       gen219/6/ut_burn.o \
       gen219/6/ut_bust.o \
       gen219/6/ut_crop.o \
       gen219/6/ut_cull.o \
       gen219/6/ut_find.o \
       gen219/6/ut_fink.o \
       gen219/6/ut_fire.o \
       gen219/6/ut_firm.o \
       gen219/6/ut_fish.o \
       gen219/6/ut_fuse.o \
       gen219/6/ut_gain.o \
       gen219/6/ut_heal.o \
       gen219/6/ut_lose.o \
       gen219/6/ut_mint.o \
       gen219/6/ut_moot.o \
       gen219/6/ut_mull.o \
       gen219/6/ut_nest.o \
       gen219/6/ut_park.o \
       gen219/6/ut_peek.o \
       gen219/6/ut_play.o \
       gen219/6/ut_repo.o \
       gen219/6/ut_rest.o \
       gen219/6/ut_seek.o \
       gen219/6/ut_snap.o \
       gen219/6/ut_swab.o \
       gen219/6/ut_tack.o \
       gen219/6/ut_tock.o \
       gen219/6/ut_wrap.o

J219_OFILES=\
       $(J219_1_OFILES) \
       $(J219_2_OFILES) \
       $(J219_3_OFILES) \
       $(J219_4_OFILES) \
       $(J219_5_OFILES) \
       $(J219_6_OFILES) \
       $(J219_6_OFILES_UT) \
       gen219/watt.o


BASE_OFILES=\
       $(C_OFILES) \
       $(F_OFILES) \
       $(P_OFILES) \
       $(J222_OFILES) \
       $(J221_OFILES) \
       $(J220_OFILES) \
       $(J219_OFILES)

OUT_OFILES=\
       outside/jhttp/http_parser.o

VERE_OFILES=\
       v/boot.o \
       v/fs.o \
       v/main.o \
       v/console.o \
       v/system.o \
       v/http.o \
       c/gunn.o \
       $(BASE_OFILES) \
       $(OUT_OFILES)

all: $(BIN)/vere

$(BIN)/vere: $(VERE_OFILES)
	mkdir -p $(BIN)
	$(CLD) -o $(BIN)/vere $(VERE_OFILES) -lev -lgmp -lreadline -ltermcap

tags:
	ctags -R -f .tags --exclude=root

clean:
	 $(RM) $(VERE_OFILES) $(BIN)/vere $(BIN)/eyre
