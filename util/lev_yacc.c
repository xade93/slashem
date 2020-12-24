/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lev_comp.y"

/*	SCCS Id: @(#)lev_yacc.c	3.4	2000/01/17	*/
/*	Copyright (c) 1989 by Jean-Christophe Collet */
/* NetHack may be freely redistributed.  See license for details. */

/*
 * This file contains the Level Compiler code
 * It may handle special mazes & special room-levels
 */

#define LEVEL_COMPILER	1	/* Enable definition of internal structures */

/* In case we're using bison in AIX.  This definition must be
 * placed before any other C-language construct in the file
 * excluding comments and preprocessor directives (thanks IBM
 * for this wonderful feature...).
 *
 * Note: some cpps barf on this 'undefined control' (#pragma).
 * Addition of the leading space seems to prevent barfage for now,
 * and AIX will still see the directive.
 */
#ifdef _AIX
 #pragma alloca		/* keep leading space! */
#endif

#include "hack.h"
#include "sp_lev.h"

#define MAX_REGISTERS	10
#define ERR		(-1)
/* many types of things are put in chars for transference to NetHack.
 * since some systems will use signed chars, limit everybody to the
 * same number for portability.
 */
#define MAX_OF_TYPE	128

#define New(type)		\
	(type *) memset((genericptr_t)alloc(sizeof(type)), 0, sizeof(type))
#define NewTab(type, size)	(type **) alloc(sizeof(type *) * size)
#define Free(ptr)		free((genericptr_t)ptr)

extern void FDECL(yyerror, (const char *));
extern void FDECL(yywarning, (const char *));
extern int NDECL(yylex);
int NDECL(yyparse);

extern int FDECL(get_artifact_id, (char *));
extern int FDECL(get_floor_type, (CHAR_P));
extern int FDECL(get_room_type, (char *));
extern int FDECL(get_trap_type, (char *));
extern int FDECL(get_monster_id, (char *,CHAR_P));
extern int FDECL(get_object_id, (char *,CHAR_P));
extern boolean FDECL(check_monster_char, (CHAR_P));
extern boolean FDECL(check_object_char, (CHAR_P));
extern char FDECL(what_map_char, (CHAR_P));
extern void FDECL(scan_map, (char *));
extern void NDECL(wallify_map);
extern boolean NDECL(check_subrooms);
extern void FDECL(check_coord, (int,int,const char *));
extern void NDECL(store_part);
extern void NDECL(store_room);
extern void FDECL(store_place_list, (int,int,int,const struct coord *));
extern boolean FDECL(write_level_file, (char *,splev *,specialmaze *));
extern void FDECL(free_rooms, (splev *));

static struct reg {
	int x1, y1;
	int x2, y2;
}		current_region;

static struct coord current_coord, current_align;

static struct size {
	int height;
	int width;
}		current_size;

char tmpmessage[256];
digpos *tmppass[32];
char *tmpmap[ROWNO];

digpos *tmpdig[MAX_OF_TYPE];
region *tmpreg[MAX_OF_TYPE];
lev_region *tmplreg[MAX_OF_TYPE];
door *tmpdoor[MAX_OF_TYPE];
drawbridge *tmpdb[MAX_OF_TYPE];
walk *tmpwalk[MAX_OF_TYPE];
lev_region *tmprndlreg[MAX_REGISTERS];

room_door *tmprdoor[MAX_OF_TYPE];
trap *tmptrap[MAX_OF_TYPE];
monster *tmpmonst[MAX_OF_TYPE];
object *tmpobj[MAX_OF_TYPE];
altar *tmpaltar[MAX_OF_TYPE];
lad *tmplad[MAX_OF_TYPE];
stair *tmpstair[MAX_OF_TYPE];
gold *tmpgold[MAX_OF_TYPE];
engraving *tmpengraving[MAX_OF_TYPE];
fountain *tmpfountain[MAX_OF_TYPE];
sink *tmpsink[MAX_OF_TYPE];
pool *tmppool[MAX_OF_TYPE];

mazepart *tmppart[10];
room *tmproom[MAXNROFROOMS*2];
corridor *tmpcor[MAX_OF_TYPE];

static specialmaze maze;
static splev special_lev;
static lev_init init_lev;

static char olist[MAX_REGISTERS], mlist[MAX_REGISTERS];
static struct coord plist[MAX_REGISTERS];

int n_olist = 0, n_mlist = 0, n_plist = 0;

unsigned int nrndlreg = 0;
unsigned int nlreg = 0, nreg = 0, ndoor = 0, ntrap = 0, nmons = 0, nobj = 0;
unsigned int ndb = 0, nwalk = 0, npart = 0, ndig = 0, nlad = 0, nstair = 0;
unsigned int naltar = 0, ncorridor = 0, nrooms = 0, ngold = 0, nengraving = 0;
unsigned int nfountain = 0, npool = 0, nsink = 0, npass = 0;

static int lev_flags = 0;

unsigned int max_x_map, max_y_map;

static xchar in_room;

extern int fatal_error;
extern int want_warnings;
extern const char *fname;


#line 204 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CHAR = 258,                    /* CHAR  */
    INTEGER = 259,                 /* INTEGER  */
    BOOLEAN = 260,                 /* BOOLEAN  */
    PERCENT = 261,                 /* PERCENT  */
    MESSAGE_ID = 262,              /* MESSAGE_ID  */
    MAZE_ID = 263,                 /* MAZE_ID  */
    LEVEL_ID = 264,                /* LEVEL_ID  */
    LEV_INIT_ID = 265,             /* LEV_INIT_ID  */
    GEOMETRY_ID = 266,             /* GEOMETRY_ID  */
    NOMAP_ID = 267,                /* NOMAP_ID  */
    OBJECT_ID = 268,               /* OBJECT_ID  */
    COBJECT_ID = 269,              /* COBJECT_ID  */
    MONSTER_ID = 270,              /* MONSTER_ID  */
    TRAP_ID = 271,                 /* TRAP_ID  */
    DOOR_ID = 272,                 /* DOOR_ID  */
    DRAWBRIDGE_ID = 273,           /* DRAWBRIDGE_ID  */
    MAZEWALK_ID = 274,             /* MAZEWALK_ID  */
    WALLIFY_ID = 275,              /* WALLIFY_ID  */
    REGION_ID = 276,               /* REGION_ID  */
    FILLING = 277,                 /* FILLING  */
    RANDOM_OBJECTS_ID = 278,       /* RANDOM_OBJECTS_ID  */
    RANDOM_MONSTERS_ID = 279,      /* RANDOM_MONSTERS_ID  */
    RANDOM_PLACES_ID = 280,        /* RANDOM_PLACES_ID  */
    ALTAR_ID = 281,                /* ALTAR_ID  */
    LADDER_ID = 282,               /* LADDER_ID  */
    STAIR_ID = 283,                /* STAIR_ID  */
    NON_DIGGABLE_ID = 284,         /* NON_DIGGABLE_ID  */
    NON_PASSWALL_ID = 285,         /* NON_PASSWALL_ID  */
    ROOM_ID = 286,                 /* ROOM_ID  */
    PORTAL_ID = 287,               /* PORTAL_ID  */
    TELEPRT_ID = 288,              /* TELEPRT_ID  */
    BRANCH_ID = 289,               /* BRANCH_ID  */
    LEV = 290,                     /* LEV  */
    CHANCE_ID = 291,               /* CHANCE_ID  */
    CORRIDOR_ID = 292,             /* CORRIDOR_ID  */
    GOLD_ID = 293,                 /* GOLD_ID  */
    ENGRAVING_ID = 294,            /* ENGRAVING_ID  */
    FOUNTAIN_ID = 295,             /* FOUNTAIN_ID  */
    POOL_ID = 296,                 /* POOL_ID  */
    SINK_ID = 297,                 /* SINK_ID  */
    NONE = 298,                    /* NONE  */
    RAND_CORRIDOR_ID = 299,        /* RAND_CORRIDOR_ID  */
    DOOR_STATE = 300,              /* DOOR_STATE  */
    LIGHT_STATE = 301,             /* LIGHT_STATE  */
    CURSE_TYPE = 302,              /* CURSE_TYPE  */
    ENGRAVING_TYPE = 303,          /* ENGRAVING_TYPE  */
    DIRECTION = 304,               /* DIRECTION  */
    RANDOM_TYPE = 305,             /* RANDOM_TYPE  */
    O_REGISTER = 306,              /* O_REGISTER  */
    M_REGISTER = 307,              /* M_REGISTER  */
    P_REGISTER = 308,              /* P_REGISTER  */
    A_REGISTER = 309,              /* A_REGISTER  */
    ALIGNMENT = 310,               /* ALIGNMENT  */
    LEFT_OR_RIGHT = 311,           /* LEFT_OR_RIGHT  */
    CENTER = 312,                  /* CENTER  */
    TOP_OR_BOT = 313,              /* TOP_OR_BOT  */
    ALTAR_TYPE = 314,              /* ALTAR_TYPE  */
    UP_OR_DOWN = 315,              /* UP_OR_DOWN  */
    SUBROOM_ID = 316,              /* SUBROOM_ID  */
    NAME_ID = 317,                 /* NAME_ID  */
    FLAGS_ID = 318,                /* FLAGS_ID  */
    FLAG_TYPE = 319,               /* FLAG_TYPE  */
    MON_ATTITUDE = 320,            /* MON_ATTITUDE  */
    MON_ALERTNESS = 321,           /* MON_ALERTNESS  */
    MON_APPEARANCE = 322,          /* MON_APPEARANCE  */
    CONTAINED = 323,               /* CONTAINED  */
    OBJFLAG_TYPE = 324,            /* OBJFLAG_TYPE  */
    OBJFLAGS_ID = 325,             /* OBJFLAGS_ID  */
    RANDOMREGION_ID = 326,         /* RANDOMREGION_ID  */
    R_REGISTER = 327,              /* R_REGISTER  */
    STRING = 328,                  /* STRING  */
    MAP_ID = 329                   /* MAP_ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CHAR 258
#define INTEGER 259
#define BOOLEAN 260
#define PERCENT 261
#define MESSAGE_ID 262
#define MAZE_ID 263
#define LEVEL_ID 264
#define LEV_INIT_ID 265
#define GEOMETRY_ID 266
#define NOMAP_ID 267
#define OBJECT_ID 268
#define COBJECT_ID 269
#define MONSTER_ID 270
#define TRAP_ID 271
#define DOOR_ID 272
#define DRAWBRIDGE_ID 273
#define MAZEWALK_ID 274
#define WALLIFY_ID 275
#define REGION_ID 276
#define FILLING 277
#define RANDOM_OBJECTS_ID 278
#define RANDOM_MONSTERS_ID 279
#define RANDOM_PLACES_ID 280
#define ALTAR_ID 281
#define LADDER_ID 282
#define STAIR_ID 283
#define NON_DIGGABLE_ID 284
#define NON_PASSWALL_ID 285
#define ROOM_ID 286
#define PORTAL_ID 287
#define TELEPRT_ID 288
#define BRANCH_ID 289
#define LEV 290
#define CHANCE_ID 291
#define CORRIDOR_ID 292
#define GOLD_ID 293
#define ENGRAVING_ID 294
#define FOUNTAIN_ID 295
#define POOL_ID 296
#define SINK_ID 297
#define NONE 298
#define RAND_CORRIDOR_ID 299
#define DOOR_STATE 300
#define LIGHT_STATE 301
#define CURSE_TYPE 302
#define ENGRAVING_TYPE 303
#define DIRECTION 304
#define RANDOM_TYPE 305
#define O_REGISTER 306
#define M_REGISTER 307
#define P_REGISTER 308
#define A_REGISTER 309
#define ALIGNMENT 310
#define LEFT_OR_RIGHT 311
#define CENTER 312
#define TOP_OR_BOT 313
#define ALTAR_TYPE 314
#define UP_OR_DOWN 315
#define SUBROOM_ID 316
#define NAME_ID 317
#define FLAGS_ID 318
#define FLAG_TYPE 319
#define MON_ATTITUDE 320
#define MON_ALERTNESS 321
#define MON_APPEARANCE 322
#define CONTAINED 323
#define OBJFLAG_TYPE 324
#define OBJFLAGS_ID 325
#define RANDOMREGION_ID 326
#define R_REGISTER 327
#define STRING 328
#define MAP_ID 329

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 135 "lev_comp.y"

	int	i;
	char*	map;
	struct {
		xchar room;
		xchar wall;
		xchar door;
	} corpos;

#line 414 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_BOOLEAN = 5,                    /* BOOLEAN  */
  YYSYMBOL_PERCENT = 6,                    /* PERCENT  */
  YYSYMBOL_MESSAGE_ID = 7,                 /* MESSAGE_ID  */
  YYSYMBOL_MAZE_ID = 8,                    /* MAZE_ID  */
  YYSYMBOL_LEVEL_ID = 9,                   /* LEVEL_ID  */
  YYSYMBOL_LEV_INIT_ID = 10,               /* LEV_INIT_ID  */
  YYSYMBOL_GEOMETRY_ID = 11,               /* GEOMETRY_ID  */
  YYSYMBOL_NOMAP_ID = 12,                  /* NOMAP_ID  */
  YYSYMBOL_OBJECT_ID = 13,                 /* OBJECT_ID  */
  YYSYMBOL_COBJECT_ID = 14,                /* COBJECT_ID  */
  YYSYMBOL_MONSTER_ID = 15,                /* MONSTER_ID  */
  YYSYMBOL_TRAP_ID = 16,                   /* TRAP_ID  */
  YYSYMBOL_DOOR_ID = 17,                   /* DOOR_ID  */
  YYSYMBOL_DRAWBRIDGE_ID = 18,             /* DRAWBRIDGE_ID  */
  YYSYMBOL_MAZEWALK_ID = 19,               /* MAZEWALK_ID  */
  YYSYMBOL_WALLIFY_ID = 20,                /* WALLIFY_ID  */
  YYSYMBOL_REGION_ID = 21,                 /* REGION_ID  */
  YYSYMBOL_FILLING = 22,                   /* FILLING  */
  YYSYMBOL_RANDOM_OBJECTS_ID = 23,         /* RANDOM_OBJECTS_ID  */
  YYSYMBOL_RANDOM_MONSTERS_ID = 24,        /* RANDOM_MONSTERS_ID  */
  YYSYMBOL_RANDOM_PLACES_ID = 25,          /* RANDOM_PLACES_ID  */
  YYSYMBOL_ALTAR_ID = 26,                  /* ALTAR_ID  */
  YYSYMBOL_LADDER_ID = 27,                 /* LADDER_ID  */
  YYSYMBOL_STAIR_ID = 28,                  /* STAIR_ID  */
  YYSYMBOL_NON_DIGGABLE_ID = 29,           /* NON_DIGGABLE_ID  */
  YYSYMBOL_NON_PASSWALL_ID = 30,           /* NON_PASSWALL_ID  */
  YYSYMBOL_ROOM_ID = 31,                   /* ROOM_ID  */
  YYSYMBOL_PORTAL_ID = 32,                 /* PORTAL_ID  */
  YYSYMBOL_TELEPRT_ID = 33,                /* TELEPRT_ID  */
  YYSYMBOL_BRANCH_ID = 34,                 /* BRANCH_ID  */
  YYSYMBOL_LEV = 35,                       /* LEV  */
  YYSYMBOL_CHANCE_ID = 36,                 /* CHANCE_ID  */
  YYSYMBOL_CORRIDOR_ID = 37,               /* CORRIDOR_ID  */
  YYSYMBOL_GOLD_ID = 38,                   /* GOLD_ID  */
  YYSYMBOL_ENGRAVING_ID = 39,              /* ENGRAVING_ID  */
  YYSYMBOL_FOUNTAIN_ID = 40,               /* FOUNTAIN_ID  */
  YYSYMBOL_POOL_ID = 41,                   /* POOL_ID  */
  YYSYMBOL_SINK_ID = 42,                   /* SINK_ID  */
  YYSYMBOL_NONE = 43,                      /* NONE  */
  YYSYMBOL_RAND_CORRIDOR_ID = 44,          /* RAND_CORRIDOR_ID  */
  YYSYMBOL_DOOR_STATE = 45,                /* DOOR_STATE  */
  YYSYMBOL_LIGHT_STATE = 46,               /* LIGHT_STATE  */
  YYSYMBOL_CURSE_TYPE = 47,                /* CURSE_TYPE  */
  YYSYMBOL_ENGRAVING_TYPE = 48,            /* ENGRAVING_TYPE  */
  YYSYMBOL_DIRECTION = 49,                 /* DIRECTION  */
  YYSYMBOL_RANDOM_TYPE = 50,               /* RANDOM_TYPE  */
  YYSYMBOL_O_REGISTER = 51,                /* O_REGISTER  */
  YYSYMBOL_M_REGISTER = 52,                /* M_REGISTER  */
  YYSYMBOL_P_REGISTER = 53,                /* P_REGISTER  */
  YYSYMBOL_A_REGISTER = 54,                /* A_REGISTER  */
  YYSYMBOL_ALIGNMENT = 55,                 /* ALIGNMENT  */
  YYSYMBOL_LEFT_OR_RIGHT = 56,             /* LEFT_OR_RIGHT  */
  YYSYMBOL_CENTER = 57,                    /* CENTER  */
  YYSYMBOL_TOP_OR_BOT = 58,                /* TOP_OR_BOT  */
  YYSYMBOL_ALTAR_TYPE = 59,                /* ALTAR_TYPE  */
  YYSYMBOL_UP_OR_DOWN = 60,                /* UP_OR_DOWN  */
  YYSYMBOL_SUBROOM_ID = 61,                /* SUBROOM_ID  */
  YYSYMBOL_NAME_ID = 62,                   /* NAME_ID  */
  YYSYMBOL_FLAGS_ID = 63,                  /* FLAGS_ID  */
  YYSYMBOL_FLAG_TYPE = 64,                 /* FLAG_TYPE  */
  YYSYMBOL_MON_ATTITUDE = 65,              /* MON_ATTITUDE  */
  YYSYMBOL_MON_ALERTNESS = 66,             /* MON_ALERTNESS  */
  YYSYMBOL_MON_APPEARANCE = 67,            /* MON_APPEARANCE  */
  YYSYMBOL_CONTAINED = 68,                 /* CONTAINED  */
  YYSYMBOL_OBJFLAG_TYPE = 69,              /* OBJFLAG_TYPE  */
  YYSYMBOL_OBJFLAGS_ID = 70,               /* OBJFLAGS_ID  */
  YYSYMBOL_RANDOMREGION_ID = 71,           /* RANDOMREGION_ID  */
  YYSYMBOL_R_REGISTER = 72,                /* R_REGISTER  */
  YYSYMBOL_73_ = 73,                       /* ','  */
  YYSYMBOL_74_ = 74,                       /* ':'  */
  YYSYMBOL_75_ = 75,                       /* '('  */
  YYSYMBOL_76_ = 76,                       /* ')'  */
  YYSYMBOL_77_ = 77,                       /* '['  */
  YYSYMBOL_78_ = 78,                       /* ']'  */
  YYSYMBOL_STRING = 79,                    /* STRING  */
  YYSYMBOL_MAP_ID = 80,                    /* MAP_ID  */
  YYSYMBOL_YYACCEPT = 81,                  /* $accept  */
  YYSYMBOL_file = 82,                      /* file  */
  YYSYMBOL_levels = 83,                    /* levels  */
  YYSYMBOL_level = 84,                     /* level  */
  YYSYMBOL_maze_level = 85,                /* maze_level  */
  YYSYMBOL_room_level = 86,                /* room_level  */
  YYSYMBOL_level_def = 87,                 /* level_def  */
  YYSYMBOL_lev_init = 88,                  /* lev_init  */
  YYSYMBOL_walled = 89,                    /* walled  */
  YYSYMBOL_flags = 90,                     /* flags  */
  YYSYMBOL_flag_list = 91,                 /* flag_list  */
  YYSYMBOL_messages = 92,                  /* messages  */
  YYSYMBOL_message = 93,                   /* message  */
  YYSYMBOL_rreg_init = 94,                 /* rreg_init  */
  YYSYMBOL_init_rreg = 95,                 /* init_rreg  */
  YYSYMBOL_rooms = 96,                     /* rooms  */
  YYSYMBOL_roomlist = 97,                  /* roomlist  */
  YYSYMBOL_corridors_def = 98,             /* corridors_def  */
  YYSYMBOL_random_corridors = 99,          /* random_corridors  */
  YYSYMBOL_corridors = 100,                /* corridors  */
  YYSYMBOL_corridor = 101,                 /* corridor  */
  YYSYMBOL_corr_spec = 102,                /* corr_spec  */
  YYSYMBOL_aroom = 103,                    /* aroom  */
  YYSYMBOL_subroom_def = 104,              /* subroom_def  */
  YYSYMBOL_room_def = 105,                 /* room_def  */
  YYSYMBOL_roomfill = 106,                 /* roomfill  */
  YYSYMBOL_room_pos = 107,                 /* room_pos  */
  YYSYMBOL_subroom_pos = 108,              /* subroom_pos  */
  YYSYMBOL_room_align = 109,               /* room_align  */
  YYSYMBOL_room_size = 110,                /* room_size  */
  YYSYMBOL_room_details = 111,             /* room_details  */
  YYSYMBOL_room_detail = 112,              /* room_detail  */
  YYSYMBOL_room_name = 113,                /* room_name  */
  YYSYMBOL_room_chance = 114,              /* room_chance  */
  YYSYMBOL_room_door = 115,                /* room_door  */
  YYSYMBOL_116_1 = 116,                    /* $@1  */
  YYSYMBOL_room_door_infos = 117,          /* room_door_infos  */
  YYSYMBOL_room_door_info = 118,           /* room_door_info  */
  YYSYMBOL_secret = 119,                   /* secret  */
  YYSYMBOL_door_wall = 120,                /* door_wall  */
  YYSYMBOL_door_pos = 121,                 /* door_pos  */
  YYSYMBOL_maze_def = 122,                 /* maze_def  */
  YYSYMBOL_filling = 123,                  /* filling  */
  YYSYMBOL_regions = 124,                  /* regions  */
  YYSYMBOL_aregion = 125,                  /* aregion  */
  YYSYMBOL_map_definition = 126,           /* map_definition  */
  YYSYMBOL_map_geometry = 127,             /* map_geometry  */
  YYSYMBOL_h_justif = 128,                 /* h_justif  */
  YYSYMBOL_v_justif = 129,                 /* v_justif  */
  YYSYMBOL_reg_init = 130,                 /* reg_init  */
  YYSYMBOL_init_reg = 131,                 /* init_reg  */
  YYSYMBOL_object_list = 132,              /* object_list  */
  YYSYMBOL_monster_list = 133,             /* monster_list  */
  YYSYMBOL_place_list = 134,               /* place_list  */
  YYSYMBOL_135_2 = 135,                    /* $@2  */
  YYSYMBOL_map_details = 136,              /* map_details  */
  YYSYMBOL_map_detail = 137,               /* map_detail  */
  YYSYMBOL_monster_detail = 138,           /* monster_detail  */
  YYSYMBOL_139_3 = 139,                    /* $@3  */
  YYSYMBOL_monster_infos = 140,            /* monster_infos  */
  YYSYMBOL_monster_info = 141,             /* monster_info  */
  YYSYMBOL_object_detail = 142,            /* object_detail  */
  YYSYMBOL_object_desc = 143,              /* object_desc  */
  YYSYMBOL_144_4 = 144,                    /* $@4  */
  YYSYMBOL_object_where = 145,             /* object_where  */
  YYSYMBOL_object_infos = 146,             /* object_infos  */
  YYSYMBOL_object_flags = 147,             /* object_flags  */
  YYSYMBOL_obj_flag_list = 148,            /* obj_flag_list  */
  YYSYMBOL_curse_state = 149,              /* curse_state  */
  YYSYMBOL_monster_id = 150,               /* monster_id  */
  YYSYMBOL_enchantment = 151,              /* enchantment  */
  YYSYMBOL_optional_name = 152,            /* optional_name  */
  YYSYMBOL_door_detail = 153,              /* door_detail  */
  YYSYMBOL_154_5 = 154,                    /* $@5  */
  YYSYMBOL_door_infos = 155,               /* door_infos  */
  YYSYMBOL_door_info = 156,                /* door_info  */
  YYSYMBOL_trap_detail = 157,              /* trap_detail  */
  YYSYMBOL_drawbridge_detail = 158,        /* drawbridge_detail  */
  YYSYMBOL_mazewalk_detail = 159,          /* mazewalk_detail  */
  YYSYMBOL_wallify_detail = 160,           /* wallify_detail  */
  YYSYMBOL_ladder_detail = 161,            /* ladder_detail  */
  YYSYMBOL_stair_detail = 162,             /* stair_detail  */
  YYSYMBOL_stair_region = 163,             /* stair_region  */
  YYSYMBOL_164_6 = 164,                    /* $@6  */
  YYSYMBOL_rndlevregion = 165,             /* rndlevregion  */
  YYSYMBOL_166_7 = 166,                    /* $@7  */
  YYSYMBOL_portal_region = 167,            /* portal_region  */
  YYSYMBOL_168_8 = 168,                    /* $@8  */
  YYSYMBOL_teleprt_region = 169,           /* teleprt_region  */
  YYSYMBOL_170_9 = 170,                    /* $@9  */
  YYSYMBOL_171_10 = 171,                   /* $@10  */
  YYSYMBOL_branch_region = 172,            /* branch_region  */
  YYSYMBOL_173_11 = 173,                   /* $@11  */
  YYSYMBOL_teleprt_detail = 174,           /* teleprt_detail  */
  YYSYMBOL_lev_region = 175,               /* lev_region  */
  YYSYMBOL_fountain_detail = 176,          /* fountain_detail  */
  YYSYMBOL_sink_detail = 177,              /* sink_detail  */
  YYSYMBOL_pool_detail = 178,              /* pool_detail  */
  YYSYMBOL_diggable_detail = 179,          /* diggable_detail  */
  YYSYMBOL_passwall_detail = 180,          /* passwall_detail  */
  YYSYMBOL_region_detail = 181,            /* region_detail  */
  YYSYMBOL_altar_detail = 182,             /* altar_detail  */
  YYSYMBOL_gold_detail = 183,              /* gold_detail  */
  YYSYMBOL_engraving_detail = 184,         /* engraving_detail  */
  YYSYMBOL_monster_c = 185,                /* monster_c  */
  YYSYMBOL_object_c = 186,                 /* object_c  */
  YYSYMBOL_m_name = 187,                   /* m_name  */
  YYSYMBOL_o_name = 188,                   /* o_name  */
  YYSYMBOL_trap_name = 189,                /* trap_name  */
  YYSYMBOL_room_type = 190,                /* room_type  */
  YYSYMBOL_prefilled = 191,                /* prefilled  */
  YYSYMBOL_coordinate = 192,               /* coordinate  */
  YYSYMBOL_door_state = 193,               /* door_state  */
  YYSYMBOL_light_state = 194,              /* light_state  */
  YYSYMBOL_alignment = 195,                /* alignment  */
  YYSYMBOL_altar_type = 196,               /* altar_type  */
  YYSYMBOL_p_register = 197,               /* p_register  */
  YYSYMBOL_r_register = 198,               /* r_register  */
  YYSYMBOL_o_register = 199,               /* o_register  */
  YYSYMBOL_m_register = 200,               /* m_register  */
  YYSYMBOL_a_register = 201,               /* a_register  */
  YYSYMBOL_place = 202,                    /* place  */
  YYSYMBOL_monster = 203,                  /* monster  */
  YYSYMBOL_object = 204,                   /* object  */
  YYSYMBOL_string = 205,                   /* string  */
  YYSYMBOL_amount = 206,                   /* amount  */
  YYSYMBOL_chance = 207,                   /* chance  */
  YYSYMBOL_engraving_type = 208,           /* engraving_type  */
  YYSYMBOL_coord = 209,                    /* coord  */
  YYSYMBOL_region = 210                    /* region  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  130
/* YYNRULES -- Number of rules.  */
#define YYNRULES  244
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  518

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   329


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      75,    76,     2,     2,    73,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    79,    80
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   174,   174,   175,   178,   179,   182,   183,   186,   213,
     250,   263,   271,   291,   292,   296,   299,   306,   310,   316,
     317,   320,   337,   338,   341,   352,   366,   380,   383,   384,
     387,   388,   391,   399,   400,   403,   418,   434,   444,   448,
     454,   472,   491,   494,   500,   510,   516,   525,   531,   536,
     542,   547,   553,   554,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   573,   582,
     596,   595,   622,   623,   626,   640,   641,   644,   645,   648,
     649,   652,   665,   669,   675,   676,   679,   685,   701,   714,
     720,   721,   724,   725,   728,   729,   732,   743,   751,   759,
     770,   776,   783,   792,   799,   808,   816,   815,   825,   826,
     829,   830,   831,   832,   833,   834,   835,   836,   837,   838,
     839,   840,   841,   842,   843,   844,   845,   846,   847,   848,
     849,   853,   852,   888,   889,   892,   896,   900,   904,   908,
     915,   918,   928,   927,   956,   965,   975,   984,   987,   990,
     995,  1003,  1007,  1013,  1017,  1023,  1034,  1038,  1044,  1045,
    1048,  1055,  1054,  1075,  1076,  1079,  1092,  1109,  1151,  1165,
    1171,  1188,  1206,  1205,  1235,  1234,  1263,  1262,  1289,  1298,
    1288,  1322,  1321,  1348,  1351,  1357,  1361,  1381,  1397,  1410,
    1423,  1438,  1453,  1519,  1537,  1554,  1572,  1573,  1577,  1580,
    1581,  1585,  1588,  1589,  1595,  1596,  1602,  1610,  1613,  1623,
    1627,  1630,  1634,  1640,  1641,  1642,  1643,  1649,  1650,  1653,
    1654,  1657,  1658,  1659,  1665,  1666,  1669,  1678,  1689,  1700,
    1709,  1718,  1727,  1728,  1735,  1746,  1758,  1761,  1762,  1766,
    1769,  1777,  1778,  1781,  1792
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "INTEGER",
  "BOOLEAN", "PERCENT", "MESSAGE_ID", "MAZE_ID", "LEVEL_ID", "LEV_INIT_ID",
  "GEOMETRY_ID", "NOMAP_ID", "OBJECT_ID", "COBJECT_ID", "MONSTER_ID",
  "TRAP_ID", "DOOR_ID", "DRAWBRIDGE_ID", "MAZEWALK_ID", "WALLIFY_ID",
  "REGION_ID", "FILLING", "RANDOM_OBJECTS_ID", "RANDOM_MONSTERS_ID",
  "RANDOM_PLACES_ID", "ALTAR_ID", "LADDER_ID", "STAIR_ID",
  "NON_DIGGABLE_ID", "NON_PASSWALL_ID", "ROOM_ID", "PORTAL_ID",
  "TELEPRT_ID", "BRANCH_ID", "LEV", "CHANCE_ID", "CORRIDOR_ID", "GOLD_ID",
  "ENGRAVING_ID", "FOUNTAIN_ID", "POOL_ID", "SINK_ID", "NONE",
  "RAND_CORRIDOR_ID", "DOOR_STATE", "LIGHT_STATE", "CURSE_TYPE",
  "ENGRAVING_TYPE", "DIRECTION", "RANDOM_TYPE", "O_REGISTER", "M_REGISTER",
  "P_REGISTER", "A_REGISTER", "ALIGNMENT", "LEFT_OR_RIGHT", "CENTER",
  "TOP_OR_BOT", "ALTAR_TYPE", "UP_OR_DOWN", "SUBROOM_ID", "NAME_ID",
  "FLAGS_ID", "FLAG_TYPE", "MON_ATTITUDE", "MON_ALERTNESS",
  "MON_APPEARANCE", "CONTAINED", "OBJFLAG_TYPE", "OBJFLAGS_ID",
  "RANDOMREGION_ID", "R_REGISTER", "','", "':'", "'('", "')'", "'['",
  "']'", "STRING", "MAP_ID", "$accept", "file", "levels", "level",
  "maze_level", "room_level", "level_def", "lev_init", "walled", "flags",
  "flag_list", "messages", "message", "rreg_init", "init_rreg", "rooms",
  "roomlist", "corridors_def", "random_corridors", "corridors", "corridor",
  "corr_spec", "aroom", "subroom_def", "room_def", "roomfill", "room_pos",
  "subroom_pos", "room_align", "room_size", "room_details", "room_detail",
  "room_name", "room_chance", "room_door", "$@1", "room_door_infos",
  "room_door_info", "secret", "door_wall", "door_pos", "maze_def",
  "filling", "regions", "aregion", "map_definition", "map_geometry",
  "h_justif", "v_justif", "reg_init", "init_reg", "object_list",
  "monster_list", "place_list", "$@2", "map_details", "map_detail",
  "monster_detail", "$@3", "monster_infos", "monster_info",
  "object_detail", "object_desc", "$@4", "object_where", "object_infos",
  "object_flags", "obj_flag_list", "curse_state", "monster_id",
  "enchantment", "optional_name", "door_detail", "$@5", "door_infos",
  "door_info", "trap_detail", "drawbridge_detail", "mazewalk_detail",
  "wallify_detail", "ladder_detail", "stair_detail", "stair_region", "$@6",
  "rndlevregion", "$@7", "portal_region", "$@8", "teleprt_region", "$@9",
  "$@10", "branch_region", "$@11", "teleprt_detail", "lev_region",
  "fountain_detail", "sink_detail", "pool_detail", "diggable_detail",
  "passwall_detail", "region_detail", "altar_detail", "gold_detail",
  "engraving_detail", "monster_c", "object_c", "m_name", "o_name",
  "trap_name", "room_type", "prefilled", "coordinate", "door_state",
  "light_state", "alignment", "altar_type", "p_register", "r_register",
  "o_register", "m_register", "a_register", "place", "monster", "object",
  "string", "amount", "chance", "engraving_type", "coord", "region", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,    44,    58,    40,    41,    91,    93,   328,
     329
};
#endif

#define YYPACT_NINF (-393)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-107)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     121,    -2,     2,   120,  -393,   121,  -393,  -393,    97,    97,
     111,   111,  -393,  -393,   119,   184,   184,  -393,   122,  -393,
     132,   124,   190,   190,    42,   126,  -393,   197,   128,  -393,
     190,   164,  -393,  -393,  -393,   132,   130,   129,    80,  -393,
     131,  -393,  -393,   164,  -393,   133,  -393,   198,  -393,   135,
     136,   140,   142,  -393,   160,  -393,    65,  -393,  -393,   125,
    -393,    16,  -393,   134,   203,   208,    56,    56,  -393,  -393,
    -393,   180,  -393,    39,    39,  -393,  -393,   145,   146,   147,
     -16,   148,  -393,     4,  -393,   214,  -393,  -393,   149,  -393,
    -393,   150,  -393,   153,  -393,   154,   155,  -393,   222,   222,
     222,   222,   156,   157,   158,   159,   161,   162,   163,   165,
     166,   167,   168,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,   127,   203,
     208,     8,   230,   234,   169,   170,   171,  -393,   172,   173,
     174,   175,   176,   177,   178,   179,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,   181,   203,
     208,    82,    82,   182,  -393,  -393,   185,  -393,   186,   187,
      23,    90,    90,   252,    43,    90,    90,    90,    90,   111,
     189,  -393,  -393,  -393,  -393,  -393,  -393,   258,  -393,   191,
    -393,   188,   192,   123,    90,    90,   193,    90,    35,   193,
     193,    15,    15,    15,   260,  -393,  -393,  -393,  -393,   194,
     196,   259,   199,    13,    32,    66,  -393,  -393,   200,  -393,
     201,   202,   204,  -393,  -393,  -393,   207,  -393,  -393,  -393,
     209,   210,  -393,  -393,  -393,  -393,  -393,   211,   212,   213,
     215,   216,  -393,  -393,   218,   219,   220,   267,   221,   223,
     206,   270,  -393,  -393,  -393,  -393,  -393,  -393,  -393,   224,
      81,    83,   225,    11,  -393,   226,   227,  -393,  -393,  -393,
     228,   229,  -393,  -393,  -393,   231,  -393,   123,   271,   272,
     117,   235,    90,   101,   232,   283,     8,     8,    15,    90,
     239,   250,   233,    82,   247,   304,   236,   237,   238,   240,
     242,    82,  -393,   312,   245,  -393,   315,   248,   273,  -393,
    -393,   316,    67,   319,    69,    90,   251,   249,   253,  -393,
     255,  -393,   256,  -393,  -393,  -393,  -393,  -393,   257,  -393,
     261,  -393,  -393,  -393,  -393,   262,  -393,   321,   263,  -393,
     265,   322,    15,    15,    15,    15,   266,   268,    84,   269,
      88,   274,   275,  -393,  -393,  -393,   276,  -393,   277,  -393,
    -393,   137,   278,  -393,   324,    68,   111,  -393,   279,  -393,
     123,   284,    56,   329,   107,   285,   286,  -393,  -393,    41,
     330,  -393,   125,   287,   336,  -393,   339,   288,    44,  -393,
     289,  -393,    90,  -393,  -393,   290,   340,   291,  -393,  -393,
    -393,  -393,    15,   292,  -393,   341,   294,   295,   296,   111,
     297,  -393,  -393,  -393,   298,   299,    88,   300,   302,   111,
    -393,  -393,   301,    89,  -393,    44,   293,  -393,  -393,   111,
    -393,   305,   326,  -393,   342,  -393,  -393,   313,  -393,  -393,
     127,   306,  -393,   345,   306,  -393,  -393,   307,  -393,  -393,
    -393,  -393,  -393,   347,   308,   309,  -393,   310,   359,  -393,
     311,  -393,    21,  -393,   317,  -393,   318,   378,   380,  -393,
    -393,  -393,  -393,  -393,  -393,   320,   323,    58,  -393,   325,
    -393,  -393,   327,    10,    45,  -393,  -393,   111,  -393,  -393,
     111,  -393,  -393,  -393,  -393,   328,   331,   331,  -393,  -393,
      45,    26,  -393,  -393,   331,  -393,  -393,  -393
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     0,     3,     4,     6,     7,    15,    15,
       0,     0,     1,     5,     0,    11,    11,   236,     0,    10,
       0,     0,    19,    19,     0,    18,    16,     0,     0,    22,
      19,     0,    82,    83,    81,     0,     0,     0,    26,    20,
       0,    87,     8,    84,    94,     0,    17,     0,    21,     0,
       0,     0,     0,    23,    33,    27,    28,    52,    52,     0,
      85,   108,    88,     0,     0,     0,     0,     0,    32,     9,
      30,    31,    29,    39,    38,    90,    91,     0,     0,     0,
       0,     0,    95,    86,   100,     0,   235,    24,   101,   234,
      25,   103,   209,     0,   208,     0,     0,    34,   239,   239,
     239,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    67,    62,    63,    64,    61,    65,    66,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,   111,   112,
     113,   114,   115,   123,   124,   125,   126,   117,   118,   119,
     120,   122,   129,   130,   116,   121,   127,   128,     0,     0,
       0,     0,     0,     0,   240,   140,     0,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    92,    89,    96,    99,   233,     0,    97,   105,
     232,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   102,   104,   219,   220,     0,
       0,     0,     0,     0,     0,     0,    75,    76,     0,   216,
       0,     0,     0,   214,   215,   213,     0,    69,   237,   238,
       0,     0,   187,   189,   188,    68,   152,   150,     0,     0,
       0,     0,   217,   218,     0,     0,     0,     0,     0,     0,
       0,     0,   172,   185,   190,   191,   176,   178,   181,     0,
       0,     0,     0,     0,   200,     0,     0,   201,   199,   197,
       0,     0,   198,   196,   207,     0,   206,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,    47,     0,     0,     0,    36,
      35,     0,     0,     0,     0,     0,     0,     0,     0,   223,
       0,   221,     0,   222,   171,   194,   241,   242,     0,   151,
       0,   107,    98,   174,   161,     0,   168,     0,     0,   170,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   205,   142,   204,     0,   203,     0,   202,
     166,     0,   226,   228,     0,     0,     0,   243,     0,   163,
       0,     0,     0,     0,     0,     0,     0,   179,   182,     0,
       0,    49,     0,     0,     0,    51,     0,     0,     0,   229,
       0,   230,     0,    77,    78,     0,     0,     0,   225,   224,
     193,   195,     0,   162,   167,     0,   210,     0,     0,     0,
     183,    13,    14,    12,     0,     0,     0,     0,     0,     0,
      79,    80,     0,     0,   131,     0,     0,   231,   175,     0,
     164,     0,     0,   192,     0,   173,   177,     0,   180,    44,
       0,    42,    46,     0,    42,    37,   145,   146,   144,   133,
      70,   227,   165,     0,   211,     0,   184,     0,     0,    41,
       0,    40,     0,   143,   132,    72,     0,     0,     0,    48,
      43,    50,   154,   153,   155,     0,     0,     0,   134,    71,
     244,   212,     0,     0,     0,   136,   137,     0,   138,   135,
       0,    73,   186,   157,   156,     0,   158,   158,   139,    74,
       0,     0,   148,   149,   158,   159,   160,   147
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -393,  -393,   383,  -393,  -393,  -393,  -393,   369,  -393,   382,
     354,    36,  -393,  -393,  -393,  -393,   343,  -393,  -393,  -393,
    -393,   138,  -393,  -393,  -393,   -62,  -393,  -393,  -393,   -31,
     344,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
     -38,  -393,  -393,   357,  -393,  -393,  -393,    14,   -45,  -393,
    -393,   -72,   -68,  -108,  -393,  -393,  -393,   332,  -393,  -393,
    -393,   333,   314,  -393,  -393,  -393,   334,  -393,  -393,   -86,
    -344,  -392,  -393,  -393,  -393,  -393,   335,  -393,  -393,  -393,
    -393,   337,  -393,  -393,  -393,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,  -393,  -393,  -200,   338,  -393,  -393,  -393,  -393,
    -393,   348,   349,   350,  -393,  -393,  -393,  -393,  -393,   -65,
    -393,  -178,  -281,  -167,   -79,  -393,  -393,  -393,  -393,  -393,
    -393,  -393,   217,   205,   -10,  -393,    91,  -393,  -127,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    22,   423,    15,
      26,    29,    30,    38,    53,    54,    55,    69,    70,    71,
      97,   222,    56,    57,    58,   469,   314,   317,   393,   397,
      73,   113,   114,   115,   116,   475,   489,   501,   228,   405,
     432,     9,    34,    42,    43,    44,    45,    77,   193,    61,
      82,    87,    90,   198,   249,    83,   146,   117,   459,   474,
     488,   118,   175,   400,   457,   473,   119,   247,   485,   486,
     506,   512,   150,   379,   413,   440,   120,   152,   153,   154,
     155,   121,   157,   307,    84,   378,   158,   308,   159,   309,
     420,   160,   310,   448,   262,   122,   123,   124,   162,   163,
     164,   125,   126,   127,   281,   276,   368,   364,   285,    93,
     443,   236,   254,   219,   332,   410,   233,   234,   277,   282,
     333,   199,    91,    88,    94,   240,   176,   338,   235,   263
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    19,    95,   232,   200,   220,   326,   241,   242,   243,
     244,   266,   267,   268,   503,   319,    86,    98,    99,   100,
     101,   134,   135,   136,   137,   138,   255,   256,   226,   259,
     103,   139,   140,   141,   142,    89,   143,   144,   145,    78,
      79,    80,   106,   107,   108,    32,   421,   238,   430,   503,
     260,   196,    98,    99,   100,   101,   102,   194,   131,    31,
     504,   132,   195,   274,   275,   103,    39,   104,   482,   515,
     260,   483,    10,   227,   112,   105,    11,   106,   107,   108,
     109,   110,   279,   197,   280,   229,   221,    81,   230,   484,
     257,   422,    33,   239,   431,   504,    51,   215,   343,   414,
     484,   111,   216,    49,    50,   516,    92,   231,   329,   112,
     261,    51,   330,   331,   335,   513,   284,   363,   408,   367,
      12,   344,   517,   495,   496,   497,    52,   409,   217,     1,
       2,   312,   218,   315,   391,    17,   348,    17,   395,   229,
     229,    52,   230,   230,   356,    17,    17,   370,    17,   336,
     507,   337,   385,   386,   387,   388,   313,   456,   316,   392,
      14,   231,   231,   396,   197,   197,   514,   329,   252,   200,
     200,   330,   331,   253,   258,    40,    41,   264,   265,   245,
     415,    75,    76,   377,   191,   192,   403,   404,   341,   342,
      17,   178,   179,    20,    21,    24,    25,    28,    27,    35,
      36,    63,    37,    47,    68,    59,    86,    85,    48,    64,
      65,    89,   438,    62,    66,   286,    67,    96,   128,   168,
     129,   130,   169,   170,   434,   133,   171,   172,   174,   173,
     180,   181,   182,   183,   201,   184,   185,   186,   202,   187,
     188,   189,   190,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   458,   237,   221,   246,   223,
     224,   225,   248,   272,  -106,   269,   250,   270,   257,   271,
     251,   302,   273,   287,   306,   327,   328,   290,   288,   289,
     291,   305,   292,   293,   294,   295,   296,   340,   345,   297,
     298,   299,   300,   301,   303,   334,   304,   311,   318,   346,
     322,   339,   324,   321,   325,   323,   347,   349,   350,   351,
     352,   353,   365,   354,   369,   355,   357,   416,   358,   359,
     362,   360,   361,   366,   371,   381,   384,   372,   407,   375,
     376,   373,   374,   417,   424,   380,   382,   377,   383,   389,
     427,   390,   394,   428,   436,   441,   465,   398,   464,   470,
     402,   476,   412,   399,   401,   406,   445,   415,   418,   419,
     426,   429,   433,   435,   480,   439,   411,   442,   444,   437,
     447,   461,   450,   466,   449,   453,   452,   455,   463,   468,
     472,   477,   478,   491,   492,    23,   479,   481,    13,    46,
     487,    16,   471,   493,   490,   451,   494,   460,   500,    72,
      60,   510,    74,   502,   511,   467,   425,   505,   498,   446,
       0,   320,     0,   177,     0,   147,   148,   149,   151,   454,
     156,   161,     0,     0,     0,     0,     0,     0,   278,   462,
       0,   165,   166,   167,     0,     0,     0,     0,     0,     0,
       0,   283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   499,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   508,     0,     0,
     509
};

static const yytype_int16 yycheck[] =
{
      10,    11,    67,   181,   131,   172,   287,   185,   186,   187,
     188,   211,   212,   213,     4,     4,     3,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   204,   205,     5,   207,
      26,    27,    28,    29,    30,     3,    32,    33,    34,    23,
      24,    25,    38,    39,    40,     3,     5,     4,     4,     4,
      35,    43,    13,    14,    15,    16,    17,   129,    74,    23,
      50,    77,   130,    50,    51,    26,    30,    28,    47,    43,
      35,    50,    74,    50,    70,    36,    74,    38,    39,    40,
      41,    42,    50,    75,    52,    50,    75,    71,    53,    79,
      75,    50,    50,    50,    50,    50,    31,   169,   298,   380,
      79,    62,   170,    23,    24,    79,    50,    72,    50,    70,
      75,    31,    54,    55,   292,   507,    50,    50,    50,    50,
       0,   299,   514,    65,    66,    67,    61,    59,    46,     8,
       9,    50,    50,    50,    50,    79,   303,    79,    50,    50,
      50,    61,    53,    53,   311,    79,    79,   325,    79,    48,
     494,    50,   352,   353,   354,   355,    75,    68,    75,    75,
      63,    72,    72,    75,    75,    75,   510,    50,    45,   296,
     297,    54,    55,    50,   206,    11,    12,   209,   210,   189,
      73,    56,    57,    76,    57,    58,    49,    50,   296,   297,
      79,   100,   101,    74,    10,    73,    64,     7,    74,    73,
       3,     3,    74,    73,    44,    74,     3,    73,    79,    74,
      74,     3,   412,    80,    74,   225,    74,    37,    73,     5,
      74,    74,    73,    73,   402,    77,    73,    73,     6,    74,
      74,    74,    74,    74,     4,    74,    74,    74,     4,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    73,   433,     4,    75,    69,    74,
      74,    74,     4,     4,    73,     5,    78,    73,    75,    73,
      78,     4,    73,    73,     4,     4,     4,    73,    77,    77,
      73,    75,    73,    73,    73,    73,    73,     4,    49,    74,
      74,    73,    73,    73,    73,    60,    73,    73,    73,    49,
      73,    69,    73,    77,    73,    77,    73,    60,     4,    73,
      73,    73,   322,    73,   324,    73,     4,   382,    73,     4,
       4,    73,    49,     4,    73,     4,     4,    78,     4,    73,
      73,    78,    77,     4,     4,    73,    73,    76,    73,    73,
       4,    73,    73,     4,     4,     4,     4,    73,    22,     4,
      73,     4,    73,    78,    78,    77,    60,    73,    73,    73,
      73,    73,    73,    73,     5,    73,   376,    73,    73,    78,
      73,    78,    73,    60,    76,    73,    76,    76,    73,    73,
      73,    73,    73,     5,     4,    16,    76,    76,     5,    35,
      73,     9,   454,    73,    76,   426,    73,   435,    73,    56,
      43,    73,    58,    76,    73,   450,   392,   493,   487,   419,
      -1,   273,    -1,    99,    -1,    83,    83,    83,    83,   429,
      83,    83,    -1,    -1,    -1,    -1,    -1,    -1,   223,   439,
      -1,    83,    83,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   487,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,
     500
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,     9,    82,    83,    84,    85,    86,    87,   122,
      74,    74,     0,    83,    63,    90,    90,    79,   205,   205,
      74,    10,    88,    88,    73,    64,    91,    74,     7,    92,
      93,    92,     3,    50,   123,    73,     3,    74,    94,    92,
      11,    12,   124,   125,   126,   127,    91,    73,    79,    23,
      24,    31,    61,    95,    96,    97,   103,   104,   105,    74,
     124,   130,    80,     3,    74,    74,    74,    74,    44,    98,
      99,   100,    97,   111,   111,    56,    57,   128,    23,    24,
      25,    71,   131,   136,   165,    73,     3,   132,   204,     3,
     133,   203,    50,   190,   205,   190,    37,   101,    13,    14,
      15,    16,    17,    26,    28,    36,    38,    39,    40,    41,
      42,    62,    70,   112,   113,   114,   115,   138,   142,   147,
     157,   162,   176,   177,   178,   182,   183,   184,    73,    74,
      74,    74,    77,    77,    17,    18,    19,    20,    21,    27,
      28,    29,    30,    32,    33,    34,   137,   138,   142,   147,
     153,   157,   158,   159,   160,   161,   162,   163,   167,   169,
     172,   176,   179,   180,   181,   182,   183,   184,     5,    73,
      73,    73,    73,    74,     6,   143,   207,   143,   207,   207,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    57,    58,   129,   132,   133,    43,    75,   134,   202,
     209,     4,     4,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    73,   132,   133,    46,    50,   194,
     194,    75,   102,    74,    74,    74,     5,    50,   119,    50,
      53,    72,   192,   197,   198,   209,   192,     4,     4,    50,
     206,   192,   192,   192,   192,   205,    69,   148,     4,   135,
      78,    78,    45,    50,   193,   192,   192,    75,   210,   192,
      35,    75,   175,   210,   210,   210,   175,   175,   175,     5,
      73,    73,     4,    73,    50,    51,   186,   199,   204,    50,
      52,   185,   200,   203,    50,   189,   205,    73,    77,    77,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    73,
      73,    73,     4,    73,    73,    75,     4,   164,   168,   170,
     173,    73,    50,    75,   107,    50,    75,   108,    73,     4,
     102,    77,    73,    77,    73,    73,   193,     4,     4,    50,
      54,    55,   195,   201,    60,   192,    48,    50,   208,    69,
       4,   134,   134,   175,   192,    49,    49,    73,   194,    60,
       4,    73,    73,    73,    73,    73,   194,     4,    73,     4,
      73,    49,     4,    50,   188,   205,     4,    50,   187,   205,
     192,    73,    78,    78,    77,    73,    73,    76,   166,   154,
      73,     4,    73,    73,     4,   175,   175,   175,   175,    73,
      73,    50,    75,   109,    73,    50,    75,   110,    73,    78,
     144,    78,    73,    49,    50,   120,    77,     4,    50,    59,
     196,   205,    73,   155,   193,    73,   190,     4,    73,    73,
     171,     5,    50,    89,     4,   128,    73,     4,     4,    73,
       4,    50,   121,    73,   192,    73,     4,    78,   175,    73,
     156,     4,    73,   191,    73,    60,   205,    73,   174,    76,
      73,   110,    76,    73,   205,    76,    68,   145,   192,   139,
     121,    78,   205,    73,    22,     4,    60,   129,    73,   106,
       4,   106,    73,   146,   140,   116,     4,    73,    73,    76,
       5,    76,    47,    50,    79,   149,   150,    73,   141,   117,
      76,     5,     4,    73,    73,    65,    66,    67,   195,   205,
      73,   118,    76,     4,    50,   150,   151,   151,   205,   205,
      73,    73,   152,   152,   151,    43,    79,   152
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    82,    83,    83,    84,    84,    85,    86,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    94,    94,    95,    95,    96,    96,    97,    97,
      98,    98,    99,   100,   100,   101,   101,   102,   103,   103,
     104,   105,   106,   106,   107,   107,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   114,
     116,   115,   117,   117,   118,   119,   119,   120,   120,   121,
     121,   122,   123,   123,   124,   124,   125,   126,   126,   127,
     128,   128,   129,   129,   130,   130,   131,   131,   131,   131,
     131,   132,   132,   133,   133,   134,   135,   134,   136,   136,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   139,   138,   140,   140,   141,   141,   141,   141,   141,
     142,   142,   144,   143,   145,   145,   146,   146,   146,   146,
     147,   148,   148,   149,   149,   150,   151,   151,   152,   152,
     152,   154,   153,   155,   155,   156,   157,   158,   159,   160,
     161,   162,   164,   163,   166,   165,   168,   167,   170,   171,
     169,   173,   172,   174,   174,   175,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   185,   185,   186,
     186,   186,   187,   187,   188,   188,   189,   189,   190,   190,
     191,   191,   191,   192,   192,   192,   192,   193,   193,   194,
     194,   195,   195,   195,   196,   196,   197,   197,   198,   199,
     200,   201,   202,   202,   203,   204,   205,   206,   206,   207,
     207,   208,   208,   209,   210
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     5,     7,
       3,     0,    13,     1,     1,     0,     3,     3,     1,     0,
       2,     3,     0,     2,     3,     3,     0,     1,     1,     2,
       1,     1,     1,     0,     2,     5,     5,     7,     2,     2,
      12,    12,     0,     2,     5,     1,     5,     1,     5,     1,
       5,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       0,    11,     0,     2,     2,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     1,     2,     3,     1,     2,     5,
       1,     1,     1,     1,     0,     2,     3,     3,     6,     3,
       1,     1,     3,     1,     3,     1,     0,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,    10,     0,     2,     2,     2,     2,     2,     3,
       2,     2,     0,     9,     1,     1,     0,     7,     5,     5,
       3,     3,     1,     1,     1,     1,     1,     1,     0,     2,
       2,     0,     7,     0,     2,     2,     6,     7,     5,     1,
       5,     5,     0,     8,     0,     9,     0,     8,     0,     0,
       8,     0,     6,     0,     2,     1,    10,     3,     3,     3,
       3,     3,     8,     7,     5,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     7,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     1,     1,     5,     9
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* maze_level: maze_def flags lev_init messages regions  */
#line 187 "lev_comp.y"
                  {
			unsigned i;

			if (fatal_error > 0) {
				(void) fprintf(stderr,
				"%s : %d errors detected. No output created!\n",
					fname, fatal_error);
			} else {
				maze.flags = (yyvsp[-3].i);
				(void) memcpy((genericptr_t)&(maze.init_lev),
						(genericptr_t)&(init_lev),
						sizeof(lev_init));
				maze.numpart = npart;
				maze.parts = NewTab(mazepart, npart);
				for(i=0;i<npart;i++)
				    maze.parts[i] = tmppart[i];
				if (!write_level_file((yyvsp[-4].map), (splev *)0, &maze)) {
					yyerror("Can't write output file!!");
					exit(EXIT_FAILURE);
				}
				npart = 0;
			}
			Free((yyvsp[-4].map));
		  }
#line 2007 "y.tab.c"
    break;

  case 9: /* room_level: level_def flags lev_init messages rreg_init rooms corridors_def  */
#line 214 "lev_comp.y"
                  {
			unsigned i;

			if (fatal_error > 0) {
			    (void) fprintf(stderr,
			      "%s : %d errors detected. No output created!\n",
					fname, fatal_error);
			} else {
				special_lev.flags = (long) (yyvsp[-5].i);
				(void) memcpy(
					(genericptr_t)&(special_lev.init_lev),
					(genericptr_t)&(init_lev),
					sizeof(lev_init));
				special_lev.nroom = nrooms;
				special_lev.rooms = NewTab(room, nrooms);
				for(i=0; i<nrooms; i++)
				    special_lev.rooms[i] = tmproom[i];
				special_lev.ncorr = ncorridor;
				special_lev.corrs = NewTab(corridor, ncorridor);
				for(i=0; i<ncorridor; i++)
				    special_lev.corrs[i] = tmpcor[i];
				if (check_subrooms()) {
				    if (!write_level_file((yyvsp[-6].map), &special_lev,
							  (specialmaze *)0)) {
					yyerror("Can't write output file!!");
					exit(EXIT_FAILURE);
				    }
				}
				free_rooms(&special_lev);
				nrooms = 0;
				ncorridor = 0;
			}
			Free((yyvsp[-6].map));
		  }
#line 2046 "y.tab.c"
    break;

  case 10: /* level_def: LEVEL_ID ':' string  */
#line 251 "lev_comp.y"
                  {
			if (index((yyvsp[0].map), '.'))
			    yyerror("Invalid dot ('.') in level name.");
			if ((int) strlen((yyvsp[0].map)) > 8)
			    yyerror("Level names limited to 8 characters.");
			(yyval.map) = (yyvsp[0].map);
			special_lev.nrmonst = special_lev.nrobjects = 0;
			n_mlist = n_olist = 0;
		  }
#line 2060 "y.tab.c"
    break;

  case 11: /* lev_init: %empty  */
#line 263 "lev_comp.y"
                  {
			/* in case we're processing multiple files,
			   explicitly clear any stale settings */
			(void) memset((genericptr_t) &init_lev, 0,
					sizeof init_lev);
			init_lev.init_present = FALSE;
			(yyval.i) = 0;
		  }
#line 2073 "y.tab.c"
    break;

  case 12: /* lev_init: LEV_INIT_ID ':' CHAR ',' CHAR ',' BOOLEAN ',' BOOLEAN ',' light_state ',' walled  */
#line 272 "lev_comp.y"
                  {
			init_lev.init_present = TRUE;
			init_lev.fg = what_map_char((char) (yyvsp[-10].i));
			if (init_lev.fg == INVALID_TYPE)
			    yyerror("Invalid foreground type.");
			init_lev.bg = what_map_char((char) (yyvsp[-8].i));
			if (init_lev.bg == INVALID_TYPE)
			    yyerror("Invalid background type.");
			init_lev.smoothed = (yyvsp[-6].i);
			init_lev.joined = (yyvsp[-4].i);
			if (init_lev.joined &&
			    init_lev.fg != CORR && init_lev.fg != ROOM)
			    yyerror("Invalid foreground type for joined map.");
			init_lev.lit = (yyvsp[-2].i);
			init_lev.walled = (yyvsp[0].i);
			(yyval.i) = 1;
		  }
#line 2095 "y.tab.c"
    break;

  case 15: /* flags: %empty  */
#line 296 "lev_comp.y"
                  {
			(yyval.i) = 0;
		  }
#line 2103 "y.tab.c"
    break;

  case 16: /* flags: FLAGS_ID ':' flag_list  */
#line 300 "lev_comp.y"
                  {
			(yyval.i) = lev_flags;
			lev_flags = 0;	/* clear for next user */
		  }
#line 2112 "y.tab.c"
    break;

  case 17: /* flag_list: FLAG_TYPE ',' flag_list  */
#line 307 "lev_comp.y"
                  {
			lev_flags |= (yyvsp[-2].i);
		  }
#line 2120 "y.tab.c"
    break;

  case 18: /* flag_list: FLAG_TYPE  */
#line 311 "lev_comp.y"
                  {
			lev_flags |= (yyvsp[0].i);
		  }
#line 2128 "y.tab.c"
    break;

  case 21: /* message: MESSAGE_ID ':' STRING  */
#line 321 "lev_comp.y"
                  {
			int i, j;

			i = (int) strlen((yyvsp[0].map)) + 1;
			j = (int) strlen(tmpmessage);
			if (i + j > 255) {
			   yyerror("Message string too long (>256 characters)");
			} else {
			    if (j) tmpmessage[j++] = '\n';
			    (void) strncpy(tmpmessage+j, (yyvsp[0].map), i - 1);
			    tmpmessage[j + i - 1] = 0;
			}
			Free((yyvsp[0].map));
		  }
#line 2147 "y.tab.c"
    break;

  case 24: /* init_rreg: RANDOM_OBJECTS_ID ':' object_list  */
#line 342 "lev_comp.y"
                  {
			if(special_lev.nrobjects) {
			    yyerror("Object registers already initialized!");
			} else {
			    special_lev.nrobjects = n_olist;
			    special_lev.robjects = (char *) alloc(n_olist);
			    (void) memcpy((genericptr_t)special_lev.robjects,
					  (genericptr_t)olist, n_olist);
			}
		  }
#line 2162 "y.tab.c"
    break;

  case 25: /* init_rreg: RANDOM_MONSTERS_ID ':' monster_list  */
#line 353 "lev_comp.y"
                  {
			if(special_lev.nrmonst) {
			    yyerror("Monster registers already initialized!");
			} else {
			    special_lev.nrmonst = n_mlist;
			    special_lev.rmonst = (char *) alloc(n_mlist);
			    (void) memcpy((genericptr_t)special_lev.rmonst,
					  (genericptr_t)mlist, n_mlist);
			  }
		  }
#line 2177 "y.tab.c"
    break;

  case 26: /* rooms: %empty  */
#line 366 "lev_comp.y"
                  {
			tmproom[nrooms] = New(room);
			tmproom[nrooms]->name = (char *) 0;
			tmproom[nrooms]->parent = (char *) 0;
			tmproom[nrooms]->rtype = 0;
			tmproom[nrooms]->rlit = 0;
			tmproom[nrooms]->xalign = ERR;
			tmproom[nrooms]->yalign = ERR;
			tmproom[nrooms]->x = 0;
			tmproom[nrooms]->y = 0;
			tmproom[nrooms]->w = 2;
			tmproom[nrooms]->h = 2;
			in_room = 1;
		  }
#line 2196 "y.tab.c"
    break;

  case 32: /* random_corridors: RAND_CORRIDOR_ID  */
#line 392 "lev_comp.y"
                  {
			tmpcor[0] = New(corridor);
			tmpcor[0]->src.room = -1;
			ncorridor = 1;
		  }
#line 2206 "y.tab.c"
    break;

  case 35: /* corridor: CORRIDOR_ID ':' corr_spec ',' corr_spec  */
#line 404 "lev_comp.y"
                  {
			tmpcor[ncorridor] = New(corridor);
			tmpcor[ncorridor]->src.room = (yyvsp[-2].corpos).room;
			tmpcor[ncorridor]->src.wall = (yyvsp[-2].corpos).wall;
			tmpcor[ncorridor]->src.door = (yyvsp[-2].corpos).door;
			tmpcor[ncorridor]->dest.room = (yyvsp[0].corpos).room;
			tmpcor[ncorridor]->dest.wall = (yyvsp[0].corpos).wall;
			tmpcor[ncorridor]->dest.door = (yyvsp[0].corpos).door;
			ncorridor++;
			if (ncorridor >= MAX_OF_TYPE) {
				yyerror("Too many corridors in level!");
				ncorridor--;
			}
		  }
#line 2225 "y.tab.c"
    break;

  case 36: /* corridor: CORRIDOR_ID ':' corr_spec ',' INTEGER  */
#line 419 "lev_comp.y"
                  {
			tmpcor[ncorridor] = New(corridor);
			tmpcor[ncorridor]->src.room = (yyvsp[-2].corpos).room;
			tmpcor[ncorridor]->src.wall = (yyvsp[-2].corpos).wall;
			tmpcor[ncorridor]->src.door = (yyvsp[-2].corpos).door;
			tmpcor[ncorridor]->dest.room = -1;
			tmpcor[ncorridor]->dest.wall = (yyvsp[0].i);
			ncorridor++;
			if (ncorridor >= MAX_OF_TYPE) {
				yyerror("Too many corridors in level!");
				ncorridor--;
			}
		  }
#line 2243 "y.tab.c"
    break;

  case 37: /* corr_spec: '(' INTEGER ',' DIRECTION ',' door_pos ')'  */
#line 435 "lev_comp.y"
                  {
			if ((unsigned) (yyvsp[-5].i) >= nrooms)
			    yyerror("Wrong room number!");
			(yyval.corpos).room = (yyvsp[-5].i);
			(yyval.corpos).wall = (yyvsp[-3].i);
			(yyval.corpos).door = (yyvsp[-1].i);
		  }
#line 2255 "y.tab.c"
    break;

  case 38: /* aroom: room_def room_details  */
#line 445 "lev_comp.y"
                  {
			store_room();
		  }
#line 2263 "y.tab.c"
    break;

  case 39: /* aroom: subroom_def room_details  */
#line 449 "lev_comp.y"
                  {
			store_room();
		  }
#line 2271 "y.tab.c"
    break;

  case 40: /* subroom_def: SUBROOM_ID ':' room_type ',' light_state ',' subroom_pos ',' room_size ',' string roomfill  */
#line 455 "lev_comp.y"
                  {
			tmproom[nrooms] = New(room);
			tmproom[nrooms]->parent = (yyvsp[-1].map);
			tmproom[nrooms]->name = (char *) 0;
			tmproom[nrooms]->rtype = (yyvsp[-9].i);
			tmproom[nrooms]->rlit = (yyvsp[-7].i);
			tmproom[nrooms]->filled = (yyvsp[0].i);
			tmproom[nrooms]->xalign = ERR;
			tmproom[nrooms]->yalign = ERR;
			tmproom[nrooms]->x = current_coord.x;
			tmproom[nrooms]->y = current_coord.y;
			tmproom[nrooms]->w = current_size.width;
			tmproom[nrooms]->h = current_size.height;
			in_room = 1;
		  }
#line 2291 "y.tab.c"
    break;

  case 41: /* room_def: ROOM_ID ':' room_type ',' light_state ',' room_pos ',' room_align ',' room_size roomfill  */
#line 473 "lev_comp.y"
                  {
			tmproom[nrooms] = New(room);
			tmproom[nrooms]->name = (char *) 0;
			tmproom[nrooms]->parent = (char *) 0;
			tmproom[nrooms]->rtype = (yyvsp[-9].i);
			tmproom[nrooms]->rlit = (yyvsp[-7].i);
			tmproom[nrooms]->filled = (yyvsp[0].i);
			tmproom[nrooms]->xalign = current_align.x;
			tmproom[nrooms]->yalign = current_align.y;
			tmproom[nrooms]->x = current_coord.x;
			tmproom[nrooms]->y = current_coord.y;
			tmproom[nrooms]->w = current_size.width;
			tmproom[nrooms]->h = current_size.height;
			in_room = 1;
		  }
#line 2311 "y.tab.c"
    break;

  case 42: /* roomfill: %empty  */
#line 491 "lev_comp.y"
                  {
			(yyval.i) = 1;
		  }
#line 2319 "y.tab.c"
    break;

  case 43: /* roomfill: ',' BOOLEAN  */
#line 495 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 2327 "y.tab.c"
    break;

  case 44: /* room_pos: '(' INTEGER ',' INTEGER ')'  */
#line 501 "lev_comp.y"
                  {
			if ( (yyvsp[-3].i) < 1 || (yyvsp[-3].i) > 5 ||
			    (yyvsp[-1].i) < 1 || (yyvsp[-1].i) > 5 ) {
			    yyerror("Room position should be between 1 & 5!");
			} else {
			    current_coord.x = (yyvsp[-3].i);
			    current_coord.y = (yyvsp[-1].i);
			}
		  }
#line 2341 "y.tab.c"
    break;

  case 45: /* room_pos: RANDOM_TYPE  */
#line 511 "lev_comp.y"
                  {
			current_coord.x = current_coord.y = ERR;
		  }
#line 2349 "y.tab.c"
    break;

  case 46: /* subroom_pos: '(' INTEGER ',' INTEGER ')'  */
#line 517 "lev_comp.y"
                  {
			if ( (yyvsp[-3].i) < 0 || (yyvsp[-1].i) < 0) {
			    yyerror("Invalid subroom position !");
			} else {
			    current_coord.x = (yyvsp[-3].i);
			    current_coord.y = (yyvsp[-1].i);
			}
		  }
#line 2362 "y.tab.c"
    break;

  case 47: /* subroom_pos: RANDOM_TYPE  */
#line 526 "lev_comp.y"
                  {
			current_coord.x = current_coord.y = ERR;
		  }
#line 2370 "y.tab.c"
    break;

  case 48: /* room_align: '(' h_justif ',' v_justif ')'  */
#line 532 "lev_comp.y"
                  {
			current_align.x = (yyvsp[-3].i);
			current_align.y = (yyvsp[-1].i);
		  }
#line 2379 "y.tab.c"
    break;

  case 49: /* room_align: RANDOM_TYPE  */
#line 537 "lev_comp.y"
                  {
			current_align.x = current_align.y = ERR;
		  }
#line 2387 "y.tab.c"
    break;

  case 50: /* room_size: '(' INTEGER ',' INTEGER ')'  */
#line 543 "lev_comp.y"
                  {
			current_size.width = (yyvsp[-3].i);
			current_size.height = (yyvsp[-1].i);
		  }
#line 2396 "y.tab.c"
    break;

  case 51: /* room_size: RANDOM_TYPE  */
#line 548 "lev_comp.y"
                  {
			current_size.height = current_size.width = ERR;
		  }
#line 2404 "y.tab.c"
    break;

  case 68: /* room_name: NAME_ID ':' string  */
#line 574 "lev_comp.y"
                  {
			if (tmproom[nrooms]->name)
			    yyerror("This room already has a name!");
			else
			    tmproom[nrooms]->name = (yyvsp[0].map);
		  }
#line 2415 "y.tab.c"
    break;

  case 69: /* room_chance: CHANCE_ID ':' INTEGER  */
#line 583 "lev_comp.y"
                   {
			if (tmproom[nrooms]->chance)
			    yyerror("This room already assigned a chance!");
			else if (tmproom[nrooms]->rtype == OROOM)
			    yyerror("Only typed rooms can have a chance!");
			else if ((yyvsp[0].i) < 1 || (yyvsp[0].i) > 99)
			    yyerror("The chance is supposed to be percentile.");
			else
			    tmproom[nrooms]->chance = (yyvsp[0].i);
		   }
#line 2430 "y.tab.c"
    break;

  case 70: /* $@1: %empty  */
#line 596 "lev_comp.y"
                  {
			/* ERR means random here */
			if ((yyvsp[-2].i) == ERR && (yyvsp[0].i) != ERR) {
		     yyerror("If the door wall is random, so must be its pos!");
			    tmprdoor[ndoor] = (struct room_door *)0;
			} else {
			    tmprdoor[ndoor] = New(room_door);
			    tmprdoor[ndoor]->secret = (yyvsp[-6].i);
			    tmprdoor[ndoor]->mask = (yyvsp[-4].i);
			    tmprdoor[ndoor]->wall = (yyvsp[-2].i);
			    tmprdoor[ndoor]->pos = (yyvsp[0].i);
			    tmprdoor[ndoor]->arti_key = 0;
			}
		  }
#line 2449 "y.tab.c"
    break;

  case 71: /* room_door: DOOR_ID ':' secret ',' door_state ',' door_wall ',' door_pos $@1 room_door_infos  */
#line 611 "lev_comp.y"
                  {
			if (tmprdoor[ndoor]) {
			    ndoor++;
			    if (ndoor >= MAX_OF_TYPE) {
				    yyerror("Too many doors in room!");
				    ndoor--;
			    }
			}
		  }
#line 2463 "y.tab.c"
    break;

  case 74: /* room_door_info: ',' string  */
#line 627 "lev_comp.y"
                  {
			int token = get_artifact_id((yyvsp[0].map));
			if (token == ERR) {
			    char ebuf[100];
			    Sprintf(ebuf, "Undefined artifact key \"%s\"", (yyvsp[0].map));
			    yyerror(ebuf);
			}
			else if (tmprdoor[ndoor])
			    tmprdoor[ndoor]->arti_key = token;
		  }
#line 2478 "y.tab.c"
    break;

  case 81: /* maze_def: MAZE_ID ':' string ',' filling  */
#line 653 "lev_comp.y"
                  {
			maze.filling = (schar) (yyvsp[0].i);
			if (index((yyvsp[-2].map), '.'))
			    yyerror("Invalid dot ('.') in level name.");
			if ((int) strlen((yyvsp[-2].map)) > 8)
			    yyerror("Level names limited to 8 characters.");
			(yyval.map) = (yyvsp[-2].map);
			in_room = 0;
			n_plist = n_mlist = n_olist = 0;
		  }
#line 2493 "y.tab.c"
    break;

  case 82: /* filling: CHAR  */
#line 666 "lev_comp.y"
                  {
			(yyval.i) = get_floor_type((char)(yyvsp[0].i));
		  }
#line 2501 "y.tab.c"
    break;

  case 83: /* filling: RANDOM_TYPE  */
#line 670 "lev_comp.y"
                  {
			(yyval.i) = -1;
		  }
#line 2509 "y.tab.c"
    break;

  case 86: /* aregion: map_definition reg_init map_details  */
#line 680 "lev_comp.y"
                  {
			store_part();
		  }
#line 2517 "y.tab.c"
    break;

  case 87: /* map_definition: NOMAP_ID  */
#line 686 "lev_comp.y"
                  {
			tmppart[npart] = New(mazepart);
			tmppart[npart]->halign = 1;
			tmppart[npart]->valign = 1;
			tmppart[npart]->nrobjects = 0;
			tmppart[npart]->nloc = 0;
			tmppart[npart]->nrmonst = 0;
			tmppart[npart]->xsize = 1;
			tmppart[npart]->ysize = 1;
			tmppart[npart]->map = (char **) alloc(sizeof(char *));
			tmppart[npart]->map[0] = (char *) alloc(1);
			tmppart[npart]->map[0][0] = STONE;
			max_x_map = COLNO-1;
			max_y_map = ROWNO;
		  }
#line 2537 "y.tab.c"
    break;

  case 88: /* map_definition: map_geometry MAP_ID  */
#line 702 "lev_comp.y"
                  {
			tmppart[npart] = New(mazepart);
			tmppart[npart]->halign = (yyvsp[-1].i) % 10;
			tmppart[npart]->valign = (yyvsp[-1].i) / 10;
			tmppart[npart]->nrobjects = 0;
			tmppart[npart]->nloc = 0;
			tmppart[npart]->nrmonst = 0;
			scan_map((yyvsp[0].map));
			Free((yyvsp[0].map));
		  }
#line 2552 "y.tab.c"
    break;

  case 89: /* map_geometry: GEOMETRY_ID ':' h_justif ',' v_justif  */
#line 715 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[-2].i) + ((yyvsp[0].i) * 10);
		  }
#line 2560 "y.tab.c"
    break;

  case 96: /* init_reg: RANDOM_OBJECTS_ID ':' object_list  */
#line 733 "lev_comp.y"
                  {
			if (tmppart[npart]->nrobjects) {
			    yyerror("Object registers already initialized!");
			} else {
			    tmppart[npart]->robjects = (char *)alloc(n_olist);
			    (void) memcpy((genericptr_t)tmppart[npart]->robjects,
					  (genericptr_t)olist, n_olist);
			    tmppart[npart]->nrobjects = n_olist;
			}
		  }
#line 2575 "y.tab.c"
    break;

  case 97: /* init_reg: RANDOM_PLACES_ID ':' place_list  */
#line 744 "lev_comp.y"
                  {
			if (tmppart[npart]->nlocset)
			    yyerror("Location registers already initialized!");
			else
			    store_place_list(npart, 0, n_plist, plist);
			n_plist = 0;
		  }
#line 2587 "y.tab.c"
    break;

  case 98: /* init_reg: RANDOM_PLACES_ID '[' INTEGER ']' ':' place_list  */
#line 752 "lev_comp.y"
                  {
			if ((yyvsp[-3].i) >= MAX_REGISTERS)
			    yyerror("Register Index overflow!");
			else
			    store_place_list(npart, (yyvsp[-3].i), n_plist, plist);
			n_plist = 0;
		  }
#line 2599 "y.tab.c"
    break;

  case 99: /* init_reg: RANDOM_MONSTERS_ID ':' monster_list  */
#line 760 "lev_comp.y"
                  {
			if (tmppart[npart]->nrmonst) {
			    yyerror("Monster registers already initialized!");
			} else {
			    tmppart[npart]->rmonst = (char *) alloc(n_mlist);
			    (void) memcpy((genericptr_t)tmppart[npart]->rmonst,
					  (genericptr_t)mlist, n_mlist);
			    tmppart[npart]->nrmonst = n_mlist;
			}
		  }
#line 2614 "y.tab.c"
    break;

  case 100: /* init_reg: rndlevregion  */
#line 771 "lev_comp.y"
                  {
			/* nothing */
		  }
#line 2622 "y.tab.c"
    break;

  case 101: /* object_list: object  */
#line 777 "lev_comp.y"
                  {
			if (n_olist < MAX_REGISTERS)
			    olist[n_olist++] = (yyvsp[0].i);
			else
			    yyerror("Object list too long!");
		  }
#line 2633 "y.tab.c"
    break;

  case 102: /* object_list: object ',' object_list  */
#line 784 "lev_comp.y"
                  {
			if (n_olist < MAX_REGISTERS)
			    olist[n_olist++] = (yyvsp[-2].i);
			else
			    yyerror("Object list too long!");
		  }
#line 2644 "y.tab.c"
    break;

  case 103: /* monster_list: monster  */
#line 793 "lev_comp.y"
                  {
			if (n_mlist < MAX_REGISTERS)
			    mlist[n_mlist++] = (yyvsp[0].i);
			else
			    yyerror("Monster list too long!");
		  }
#line 2655 "y.tab.c"
    break;

  case 104: /* monster_list: monster ',' monster_list  */
#line 800 "lev_comp.y"
                  {
			if (n_mlist < MAX_REGISTERS)
			    mlist[n_mlist++] = (yyvsp[-2].i);
			else
			    yyerror("Monster list too long!");
		  }
#line 2666 "y.tab.c"
    break;

  case 105: /* place_list: place  */
#line 809 "lev_comp.y"
                  {
			if (n_plist < MAX_REGISTERS)
			    plist[n_plist++] = current_coord;
			else
			    yyerror("Location list too long!");
		  }
#line 2677 "y.tab.c"
    break;

  case 106: /* $@2: %empty  */
#line 816 "lev_comp.y"
                  {
			if (n_plist < MAX_REGISTERS)
			    plist[n_plist++] = current_coord;
			else
			    yyerror("Location list too long!");
		  }
#line 2688 "y.tab.c"
    break;

  case 131: /* $@3: %empty  */
#line 853 "lev_comp.y"
                  {
			tmpmonst[nmons] = New(monster);
			tmpmonst[nmons]->x = current_coord.x;
			tmpmonst[nmons]->y = current_coord.y;
			tmpmonst[nmons]->class = (yyvsp[-4].i);
			tmpmonst[nmons]->peaceful = -1; /* no override */
			tmpmonst[nmons]->asleep = -1;
			tmpmonst[nmons]->align = - MAX_REGISTERS - 2;
			tmpmonst[nmons]->name.str = 0;
			tmpmonst[nmons]->appear = 0;
			tmpmonst[nmons]->appear_as.str = 0;
			tmpmonst[nmons]->chance = (yyvsp[-6].i);
			tmpmonst[nmons]->id = NON_PM;
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Monster");
			if ((yyvsp[-2].map)) {
			    int token = get_monster_id((yyvsp[-2].map), (char) (yyvsp[-4].i));
			    if (token == ERR)
				yywarning(
			      "Invalid monster name!  Making random monster.");
			    else
				tmpmonst[nmons]->id = token;
			    Free((yyvsp[-2].map));
			}
		  }
#line 2719 "y.tab.c"
    break;

  case 132: /* monster_detail: MONSTER_ID chance ':' monster_c ',' m_name ',' coordinate $@3 monster_infos  */
#line 880 "lev_comp.y"
                  {
			if (++nmons >= MAX_OF_TYPE) {
			    yyerror("Too many monsters in room or mazepart!");
			    nmons--;
			}
		  }
#line 2730 "y.tab.c"
    break;

  case 135: /* monster_info: ',' string  */
#line 893 "lev_comp.y"
                  {
			tmpmonst[nmons]->name.str = (yyvsp[0].map);
		  }
#line 2738 "y.tab.c"
    break;

  case 136: /* monster_info: ',' MON_ATTITUDE  */
#line 897 "lev_comp.y"
                  {
			tmpmonst[nmons]->peaceful = (yyvsp[0].i);
		  }
#line 2746 "y.tab.c"
    break;

  case 137: /* monster_info: ',' MON_ALERTNESS  */
#line 901 "lev_comp.y"
                  {
			tmpmonst[nmons]->asleep = (yyvsp[0].i);
		  }
#line 2754 "y.tab.c"
    break;

  case 138: /* monster_info: ',' alignment  */
#line 905 "lev_comp.y"
                  {
			tmpmonst[nmons]->align = (yyvsp[0].i);
		  }
#line 2762 "y.tab.c"
    break;

  case 139: /* monster_info: ',' MON_APPEARANCE string  */
#line 909 "lev_comp.y"
                  {
			tmpmonst[nmons]->appear = (yyvsp[-1].i);
			tmpmonst[nmons]->appear_as.str = (yyvsp[0].map);
		  }
#line 2771 "y.tab.c"
    break;

  case 140: /* object_detail: OBJECT_ID object_desc  */
#line 916 "lev_comp.y"
                  {
		  }
#line 2778 "y.tab.c"
    break;

  case 141: /* object_detail: COBJECT_ID object_desc  */
#line 919 "lev_comp.y"
                  {
			/* 1: is contents of preceeding object with 2 */
			/* 2: is a container */
			/* 0: neither */
			tmpobj[nobj-1]->containment = 2;
		  }
#line 2789 "y.tab.c"
    break;

  case 142: /* $@4: %empty  */
#line 928 "lev_comp.y"
                  {
			tmpobj[nobj] = New(object);
			tmpobj[nobj]->class = (yyvsp[-2].i);
			tmpobj[nobj]->corpsenm = NON_PM;
			tmpobj[nobj]->curse_state = -1;
			tmpobj[nobj]->name.str = 0;
			tmpobj[nobj]->chance = (yyvsp[-4].i);
			tmpobj[nobj]->id = -1;
			tmpobj[nobj]->oflags = 0;
			if ((yyvsp[0].map)) {
			    int token = get_object_id((yyvsp[0].map), (yyvsp[-2].i));
			    if (token == ERR)
				yywarning(
				"Illegal object name!  Making random object.");
			     else
				tmpobj[nobj]->id = token;
			    Free((yyvsp[0].map));
			}
		  }
#line 2813 "y.tab.c"
    break;

  case 143: /* object_desc: chance ':' object_c ',' o_name $@4 ',' object_where object_infos  */
#line 948 "lev_comp.y"
                  {
			if (++nobj >= MAX_OF_TYPE) {
			    yyerror("Too many objects in room or mazepart!");
			    nobj--;
			}
		  }
#line 2824 "y.tab.c"
    break;

  case 144: /* object_where: coordinate  */
#line 957 "lev_comp.y"
                  {
			tmpobj[nobj]->containment = 0;
			tmpobj[nobj]->x = current_coord.x;
			tmpobj[nobj]->y = current_coord.y;
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Object");
		  }
#line 2837 "y.tab.c"
    break;

  case 145: /* object_where: CONTAINED  */
#line 966 "lev_comp.y"
                  {
			tmpobj[nobj]->containment = 1;
			/* random coordinate, will be overridden anyway */
			tmpobj[nobj]->x = -MAX_REGISTERS-2;
			tmpobj[nobj]->y = -MAX_REGISTERS-2;
		  }
#line 2848 "y.tab.c"
    break;

  case 146: /* object_infos: %empty  */
#line 975 "lev_comp.y"
                  {
			tmpobj[nobj]->spe = -127;
	/* Note below: we're trying to make as many of these optional as
	 * possible.  We clearly can't make curse_state, enchantment, and
	 * monster_id _all_ optional, since ",random" would be ambiguous.
	 * We can't even just make enchantment mandatory, since if we do that
	 * alone, ",random" requires too much lookahead to parse.
	 */
		  }
#line 2862 "y.tab.c"
    break;

  case 147: /* object_infos: ',' curse_state ',' monster_id ',' enchantment optional_name  */
#line 985 "lev_comp.y"
                  {
		  }
#line 2869 "y.tab.c"
    break;

  case 148: /* object_infos: ',' curse_state ',' enchantment optional_name  */
#line 988 "lev_comp.y"
                  {
		  }
#line 2876 "y.tab.c"
    break;

  case 149: /* object_infos: ',' monster_id ',' enchantment optional_name  */
#line 991 "lev_comp.y"
                  {
		  }
#line 2883 "y.tab.c"
    break;

  case 150: /* object_flags: OBJFLAGS_ID ':' obj_flag_list  */
#line 996 "lev_comp.y"
                  {
		   	if (nobj > 0)
		   	   tmpobj[nobj-1]->oflags = (yyvsp[0].i);
			else yyerror("Need an object before object flags!");
		  }
#line 2893 "y.tab.c"
    break;

  case 151: /* obj_flag_list: obj_flag_list ',' OBJFLAG_TYPE  */
#line 1004 "lev_comp.y"
                  {
		     (yyval.i) = ((yyvsp[-2].i) | (yyvsp[0].i));
		  }
#line 2901 "y.tab.c"
    break;

  case 152: /* obj_flag_list: OBJFLAG_TYPE  */
#line 1008 "lev_comp.y"
                  {
		     (yyval.i) = (yyvsp[0].i);
		  }
#line 2909 "y.tab.c"
    break;

  case 153: /* curse_state: RANDOM_TYPE  */
#line 1014 "lev_comp.y"
                  {
			tmpobj[nobj]->curse_state = -1;
		  }
#line 2917 "y.tab.c"
    break;

  case 154: /* curse_state: CURSE_TYPE  */
#line 1018 "lev_comp.y"
                  {
			tmpobj[nobj]->curse_state = (yyvsp[0].i);
		  }
#line 2925 "y.tab.c"
    break;

  case 155: /* monster_id: STRING  */
#line 1024 "lev_comp.y"
                  {
			int token = get_monster_id((yyvsp[0].map), (char)0);
			if (token == ERR)	/* "random" */
			    tmpobj[nobj]->corpsenm = NON_PM - 1;
			else
			    tmpobj[nobj]->corpsenm = token;
			Free((yyvsp[0].map));
		  }
#line 2938 "y.tab.c"
    break;

  case 156: /* enchantment: RANDOM_TYPE  */
#line 1035 "lev_comp.y"
                  {
			tmpobj[nobj]->spe = -127;
		  }
#line 2946 "y.tab.c"
    break;

  case 157: /* enchantment: INTEGER  */
#line 1039 "lev_comp.y"
                  {
			tmpobj[nobj]->spe = (yyvsp[0].i);
		  }
#line 2954 "y.tab.c"
    break;

  case 159: /* optional_name: ',' NONE  */
#line 1046 "lev_comp.y"
                  {
		  }
#line 2961 "y.tab.c"
    break;

  case 160: /* optional_name: ',' STRING  */
#line 1049 "lev_comp.y"
                  {
			tmpobj[nobj]->name.str = (yyvsp[0].map);
		  }
#line 2969 "y.tab.c"
    break;

  case 161: /* $@5: %empty  */
#line 1055 "lev_comp.y"
                  {
			tmpdoor[ndoor] = New(door);
			tmpdoor[ndoor]->x = current_coord.x;
			tmpdoor[ndoor]->y = current_coord.y;
			tmpdoor[ndoor]->mask = (yyvsp[-2].i);
			tmpdoor[ndoor]->arti_key = 0;
			if(current_coord.x >= 0 && current_coord.y >= 0 &&
			   tmpmap[current_coord.y][current_coord.x] != DOOR &&
			   tmpmap[current_coord.y][current_coord.x] != SDOOR)
			    yyerror("Door decl doesn't match the map");
		  }
#line 2985 "y.tab.c"
    break;

  case 162: /* door_detail: DOOR_ID ':' door_state ',' coordinate $@5 door_infos  */
#line 1067 "lev_comp.y"
                  {
			if (++ndoor >= MAX_OF_TYPE) {
			    yyerror("Too many doors in mazepart!");
			    ndoor--;
			}
		  }
#line 2996 "y.tab.c"
    break;

  case 165: /* door_info: ',' string  */
#line 1080 "lev_comp.y"
                  {
			int token = get_artifact_id((yyvsp[0].map));
			if (token == ERR) {
			    char ebuf[100];
			    Sprintf(ebuf, "Undefined artifact key \"%s\"", (yyvsp[0].map));
			    yyerror(ebuf);
			}
			else
			    tmpdoor[ndoor]->arti_key = token;
		  }
#line 3011 "y.tab.c"
    break;

  case 166: /* trap_detail: TRAP_ID chance ':' trap_name ',' coordinate  */
#line 1093 "lev_comp.y"
                  {
			tmptrap[ntrap] = New(trap);
			tmptrap[ntrap]->x = current_coord.x;
			tmptrap[ntrap]->y = current_coord.y;
			tmptrap[ntrap]->type = (yyvsp[-2].i);
			tmptrap[ntrap]->chance = (yyvsp[-4].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Trap");
			if (++ntrap >= MAX_OF_TYPE) {
				yyerror("Too many traps in room or mazepart!");
				ntrap--;
			}
		  }
#line 3030 "y.tab.c"
    break;

  case 167: /* drawbridge_detail: DRAWBRIDGE_ID ':' coordinate ',' DIRECTION ',' door_state  */
#line 1110 "lev_comp.y"
                   {
		        int x, y, dir;

			tmpdb[ndb] = New(drawbridge);
			x = tmpdb[ndb]->x = current_coord.x;
			y = tmpdb[ndb]->y = current_coord.y;
			/* convert dir from a DIRECTION to a DB_DIR */
			dir = (yyvsp[-2].i);
			switch(dir) {
			case W_NORTH: dir = DB_NORTH; y--; break;
			case W_SOUTH: dir = DB_SOUTH; y++; break;
			case W_EAST:  dir = DB_EAST;  x++; break;
			case W_WEST:  dir = DB_WEST;  x--; break;
			default:
			    yyerror("Invalid drawbridge direction");
			    break;
			}
			tmpdb[ndb]->dir = dir;
			if (current_coord.x >= 0 && current_coord.y >= 0 &&
			    !IS_WALL(tmpmap[y][x])) {
			    char ebuf[60];
			    Sprintf(ebuf,
				    "Wall needed for drawbridge (%02d, %02d)",
				    current_coord.x, current_coord.y);
			    yyerror(ebuf);
			}

			if ( (yyvsp[0].i) == D_ISOPEN )
			    tmpdb[ndb]->db_open = 1;
			else if ( (yyvsp[0].i) == D_CLOSED )
			    tmpdb[ndb]->db_open = 0;
			else
			    yyerror("A drawbridge can only be open or closed!");
			ndb++;
			if (ndb >= MAX_OF_TYPE) {
				yyerror("Too many drawbridges in mazepart!");
				ndb--;
			}
		   }
#line 3074 "y.tab.c"
    break;

  case 168: /* mazewalk_detail: MAZEWALK_ID ':' coordinate ',' DIRECTION  */
#line 1152 "lev_comp.y"
                  {
			tmpwalk[nwalk] = New(walk);
			tmpwalk[nwalk]->x = current_coord.x;
			tmpwalk[nwalk]->y = current_coord.y;
			tmpwalk[nwalk]->dir = (yyvsp[0].i);
			nwalk++;
			if (nwalk >= MAX_OF_TYPE) {
				yyerror("Too many mazewalks in mazepart!");
				nwalk--;
			}
		  }
#line 3090 "y.tab.c"
    break;

  case 169: /* wallify_detail: WALLIFY_ID  */
#line 1166 "lev_comp.y"
                  {
			wallify_map();
		  }
#line 3098 "y.tab.c"
    break;

  case 170: /* ladder_detail: LADDER_ID ':' coordinate ',' UP_OR_DOWN  */
#line 1172 "lev_comp.y"
                  {
			tmplad[nlad] = New(lad);
			tmplad[nlad]->x = current_coord.x;
			tmplad[nlad]->y = current_coord.y;
			tmplad[nlad]->up = (yyvsp[0].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Ladder");
			nlad++;
			if (nlad >= MAX_OF_TYPE) {
				yyerror("Too many ladders in mazepart!");
				nlad--;
			}
		  }
#line 3117 "y.tab.c"
    break;

  case 171: /* stair_detail: STAIR_ID ':' coordinate ',' UP_OR_DOWN  */
#line 1189 "lev_comp.y"
                  {
			tmpstair[nstair] = New(stair);
			tmpstair[nstair]->x = current_coord.x;
			tmpstair[nstair]->y = current_coord.y;
			tmpstair[nstair]->up = (yyvsp[0].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Stairway");
			nstair++;
			if (nstair >= MAX_OF_TYPE) {
				yyerror("Too many stairs in room or mazepart!");
				nstair--;
			}
		  }
#line 3136 "y.tab.c"
    break;

  case 172: /* $@6: %empty  */
#line 1206 "lev_comp.y"
                  {
			tmplreg[nlreg] = New(lev_region);
			tmplreg[nlreg]->in_islev = (yyvsp[0].i);
			tmplreg[nlreg]->inarea.x1 = current_region.x1;
			tmplreg[nlreg]->inarea.y1 = current_region.y1;
			tmplreg[nlreg]->inarea.x2 = current_region.x2;
			tmplreg[nlreg]->inarea.y2 = current_region.y2;
		  }
#line 3149 "y.tab.c"
    break;

  case 173: /* stair_region: STAIR_ID ':' lev_region $@6 ',' lev_region ',' UP_OR_DOWN  */
#line 1215 "lev_comp.y"
                  {
			tmplreg[nlreg]->del_islev = (yyvsp[-2].i);
			tmplreg[nlreg]->delarea.x1 = current_region.x1;
			tmplreg[nlreg]->delarea.y1 = current_region.y1;
			tmplreg[nlreg]->delarea.x2 = current_region.x2;
			tmplreg[nlreg]->delarea.y2 = current_region.y2;
			if((yyvsp[0].i))
			    tmplreg[nlreg]->rtype = LR_UPSTAIR;
			else
			    tmplreg[nlreg]->rtype = LR_DOWNSTAIR;
			tmplreg[nlreg]->rname.str = 0;
			nlreg++;
			if (nlreg >= MAX_OF_TYPE) {
				yyerror("Too many levregions in mazepart!");
				nlreg--;
			}
		  }
#line 3171 "y.tab.c"
    break;

  case 174: /* $@7: %empty  */
#line 1235 "lev_comp.y"
                  {
		   	if ((unsigned) (yyvsp[-3].i) != nrndlreg)
			    yyerror("Wrong random region number!");
			tmprndlreg[nrndlreg] = New(lev_region);
			tmprndlreg[nrndlreg]->in_islev = (yyvsp[0].i);
			tmprndlreg[nrndlreg]->inarea.x1 = current_region.x1;
			tmprndlreg[nrndlreg]->inarea.y1 = current_region.y1;
			tmprndlreg[nrndlreg]->inarea.x2 = current_region.x2;
			tmprndlreg[nrndlreg]->inarea.y2 = current_region.y2;
		  }
#line 3186 "y.tab.c"
    break;

  case 175: /* rndlevregion: RANDOMREGION_ID '[' INTEGER ']' ':' lev_region $@7 ',' lev_region  */
#line 1246 "lev_comp.y"
                  {
		   	tmprndlreg[nrndlreg]->del_islev = (yyvsp[0].i);
			tmprndlreg[nrndlreg]->delarea.x1 = current_region.x1;
			tmprndlreg[nrndlreg]->delarea.y1 = current_region.y1;
			tmprndlreg[nrndlreg]->delarea.x2 = current_region.x2;
			tmprndlreg[nrndlreg]->delarea.y2 = current_region.y2;
			tmprndlreg[nrndlreg]->rtype = 0;
			tmprndlreg[nrndlreg]->rname.str = (char *)0;
			nrndlreg++;
			if (nrndlreg >= MAX_REGISTERS) {
				yyerror("Too many random regions!");
				nrndlreg--;
			}
		  }
#line 3205 "y.tab.c"
    break;

  case 176: /* $@8: %empty  */
#line 1263 "lev_comp.y"
                  {
			tmplreg[nlreg] = New(lev_region);
			tmplreg[nlreg]->in_islev = (yyvsp[0].i);
			tmplreg[nlreg]->inarea.x1 = current_region.x1;
			tmplreg[nlreg]->inarea.y1 = current_region.y1;
			tmplreg[nlreg]->inarea.x2 = current_region.x2;
			tmplreg[nlreg]->inarea.y2 = current_region.y2;
		  }
#line 3218 "y.tab.c"
    break;

  case 177: /* portal_region: PORTAL_ID ':' lev_region $@8 ',' lev_region ',' string  */
#line 1272 "lev_comp.y"
                  {
			tmplreg[nlreg]->del_islev = (yyvsp[-2].i);
			tmplreg[nlreg]->delarea.x1 = current_region.x1;
			tmplreg[nlreg]->delarea.y1 = current_region.y1;
			tmplreg[nlreg]->delarea.x2 = current_region.x2;
			tmplreg[nlreg]->delarea.y2 = current_region.y2;
			tmplreg[nlreg]->rtype = LR_PORTAL;
			tmplreg[nlreg]->rname.str = (yyvsp[0].map);
			nlreg++;
			if (nlreg >= MAX_OF_TYPE) {
				yyerror("Too many levregions in mazepart!");
				nlreg--;
			}
		  }
#line 3237 "y.tab.c"
    break;

  case 178: /* $@9: %empty  */
#line 1289 "lev_comp.y"
                  {
			tmplreg[nlreg] = New(lev_region);
			tmplreg[nlreg]->in_islev = (yyvsp[0].i);
			tmplreg[nlreg]->inarea.x1 = current_region.x1;
			tmplreg[nlreg]->inarea.y1 = current_region.y1;
			tmplreg[nlreg]->inarea.x2 = current_region.x2;
			tmplreg[nlreg]->inarea.y2 = current_region.y2;
		  }
#line 3250 "y.tab.c"
    break;

  case 179: /* $@10: %empty  */
#line 1298 "lev_comp.y"
                  {
			tmplreg[nlreg]->del_islev = (yyvsp[0].i);
			tmplreg[nlreg]->delarea.x1 = current_region.x1;
			tmplreg[nlreg]->delarea.y1 = current_region.y1;
			tmplreg[nlreg]->delarea.x2 = current_region.x2;
			tmplreg[nlreg]->delarea.y2 = current_region.y2;
		  }
#line 3262 "y.tab.c"
    break;

  case 180: /* teleprt_region: TELEPRT_ID ':' lev_region $@9 ',' lev_region $@10 teleprt_detail  */
#line 1306 "lev_comp.y"
                  {
			switch((yyvsp[0].i)) {
			case -1: tmplreg[nlreg]->rtype = LR_TELE; break;
			case 0: tmplreg[nlreg]->rtype = LR_DOWNTELE; break;
			case 1: tmplreg[nlreg]->rtype = LR_UPTELE; break;
			}
			tmplreg[nlreg]->rname.str = 0;
			nlreg++;
			if (nlreg >= MAX_OF_TYPE) {
				yyerror("Too many levregions in mazepart!");
				nlreg--;
			}
		  }
#line 3280 "y.tab.c"
    break;

  case 181: /* $@11: %empty  */
#line 1322 "lev_comp.y"
                  {
			tmplreg[nlreg] = New(lev_region);
			tmplreg[nlreg]->in_islev = (yyvsp[0].i);
			tmplreg[nlreg]->inarea.x1 = current_region.x1;
			tmplreg[nlreg]->inarea.y1 = current_region.y1;
			tmplreg[nlreg]->inarea.x2 = current_region.x2;
			tmplreg[nlreg]->inarea.y2 = current_region.y2;
		  }
#line 3293 "y.tab.c"
    break;

  case 182: /* branch_region: BRANCH_ID ':' lev_region $@11 ',' lev_region  */
#line 1331 "lev_comp.y"
                  {
			tmplreg[nlreg]->del_islev = (yyvsp[0].i);
			tmplreg[nlreg]->delarea.x1 = current_region.x1;
			tmplreg[nlreg]->delarea.y1 = current_region.y1;
			tmplreg[nlreg]->delarea.x2 = current_region.x2;
			tmplreg[nlreg]->delarea.y2 = current_region.y2;
			tmplreg[nlreg]->rtype = LR_BRANCH;
			tmplreg[nlreg]->rname.str = 0;
			nlreg++;
			if (nlreg >= MAX_OF_TYPE) {
				yyerror("Too many levregions in mazepart!");
				nlreg--;
			}
		  }
#line 3312 "y.tab.c"
    break;

  case 183: /* teleprt_detail: %empty  */
#line 1348 "lev_comp.y"
                  {
			(yyval.i) = -1;
		  }
#line 3320 "y.tab.c"
    break;

  case 184: /* teleprt_detail: ',' UP_OR_DOWN  */
#line 1352 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 3328 "y.tab.c"
    break;

  case 185: /* lev_region: region  */
#line 1358 "lev_comp.y"
                  {
			(yyval.i) = 0;
		  }
#line 3336 "y.tab.c"
    break;

  case 186: /* lev_region: LEV '(' INTEGER ',' INTEGER ',' INTEGER ',' INTEGER ')'  */
#line 1362 "lev_comp.y"
                  {
/* This series of if statements is a hack for MSC 5.1.  It seems that its
   tiny little brain cannot compile if these are all one big if statement. */
			if ((yyvsp[-7].i) <= 0 || (yyvsp[-7].i) >= COLNO)
				yyerror("Region out of level range!");
			else if ((yyvsp[-5].i) < 0 || (yyvsp[-5].i) >= ROWNO)
				yyerror("Region out of level range!");
			else if ((yyvsp[-3].i) <= 0 || (yyvsp[-3].i) >= COLNO)
				yyerror("Region out of level range!");
			else if ((yyvsp[-1].i) < 0 || (yyvsp[-1].i) >= ROWNO)
				yyerror("Region out of level range!");
			current_region.x1 = (yyvsp[-7].i);
			current_region.y1 = (yyvsp[-5].i);
			current_region.x2 = (yyvsp[-3].i);
			current_region.y2 = (yyvsp[-1].i);
			(yyval.i) = 1;
		  }
#line 3358 "y.tab.c"
    break;

  case 187: /* fountain_detail: FOUNTAIN_ID ':' coordinate  */
#line 1382 "lev_comp.y"
                  {
			tmpfountain[nfountain] = New(fountain);
			tmpfountain[nfountain]->x = current_coord.x;
			tmpfountain[nfountain]->y = current_coord.y;
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Fountain");
			nfountain++;
			if (nfountain >= MAX_OF_TYPE) {
			    yyerror("Too many fountains in room or mazepart!");
			    nfountain--;
			}
		  }
#line 3376 "y.tab.c"
    break;

  case 188: /* sink_detail: SINK_ID ':' coordinate  */
#line 1398 "lev_comp.y"
                  {
			tmpsink[nsink] = New(sink);
			tmpsink[nsink]->x = current_coord.x;
			tmpsink[nsink]->y = current_coord.y;
			nsink++;
			if (nsink >= MAX_OF_TYPE) {
				yyerror("Too many sinks in room!");
				nsink--;
			}
		  }
#line 3391 "y.tab.c"
    break;

  case 189: /* pool_detail: POOL_ID ':' coordinate  */
#line 1411 "lev_comp.y"
                  {
			tmppool[npool] = New(pool);
			tmppool[npool]->x = current_coord.x;
			tmppool[npool]->y = current_coord.y;
			npool++;
			if (npool >= MAX_OF_TYPE) {
				yyerror("Too many pools in room!");
				npool--;
			}
		  }
#line 3406 "y.tab.c"
    break;

  case 190: /* diggable_detail: NON_DIGGABLE_ID ':' region  */
#line 1424 "lev_comp.y"
                  {
			tmpdig[ndig] = New(digpos);
			tmpdig[ndig]->x1 = current_region.x1;
			tmpdig[ndig]->y1 = current_region.y1;
			tmpdig[ndig]->x2 = current_region.x2;
			tmpdig[ndig]->y2 = current_region.y2;
			ndig++;
			if (ndig >= MAX_OF_TYPE) {
				yyerror("Too many diggables in mazepart!");
				ndig--;
			}
		  }
#line 3423 "y.tab.c"
    break;

  case 191: /* passwall_detail: NON_PASSWALL_ID ':' region  */
#line 1439 "lev_comp.y"
                  {
			tmppass[npass] = New(digpos);
			tmppass[npass]->x1 = current_region.x1;
			tmppass[npass]->y1 = current_region.y1;
			tmppass[npass]->x2 = current_region.x2;
			tmppass[npass]->y2 = current_region.y2;
			npass++;
			if (npass >= 32) {
				yyerror("Too many passwalls in mazepart!");
				npass--;
			}
		  }
#line 3440 "y.tab.c"
    break;

  case 192: /* region_detail: REGION_ID ':' region ',' light_state ',' room_type prefilled  */
#line 1454 "lev_comp.y"
                  {
			tmpreg[nreg] = New(region);
			tmpreg[nreg]->x1 = current_region.x1;
			tmpreg[nreg]->y1 = current_region.y1;
			tmpreg[nreg]->x2 = current_region.x2;
			tmpreg[nreg]->y2 = current_region.y2;
			tmpreg[nreg]->rlit = (yyvsp[-3].i);
			tmpreg[nreg]->rtype = (yyvsp[-1].i);
			if((yyvsp[0].i) & 1) tmpreg[nreg]->rtype += MAXRTYPE+1;
			tmpreg[nreg]->rirreg = (((yyvsp[0].i) & 2) != 0);
			if(current_region.x1 > current_region.x2 ||
			   current_region.y1 > current_region.y2)
			   yyerror("Region start > end!");
			if(tmpreg[nreg]->rtype == VAULT &&
			   (tmpreg[nreg]->rirreg ||
			    (tmpreg[nreg]->x2 - tmpreg[nreg]->x1 != 1) ||
			    (tmpreg[nreg]->y2 - tmpreg[nreg]->y1 != 1)))
				yyerror("Vaults must be exactly 2x2!");
			if(want_warnings && !tmpreg[nreg]->rirreg &&
			   current_region.x1 > 0 && current_region.y1 > 0 &&
			   current_region.x2 < (int)max_x_map &&
			   current_region.y2 < (int)max_y_map) {
			    /* check for walls in the room */
			    char ebuf[60];
			    register int x, y, nrock = 0;

			    for(y=current_region.y1; y<=current_region.y2; y++)
				for(x=current_region.x1;
				    x<=current_region.x2; x++)
				    if(IS_ROCK(tmpmap[y][x]) ||
				       IS_DOOR(tmpmap[y][x])) nrock++;
			    if(nrock) {
				Sprintf(ebuf,
					"Rock in room (%02d,%02d,%02d,%02d)?!",
					current_region.x1, current_region.y1,
					current_region.x2, current_region.y2);
				yywarning(ebuf);
			    }
			    if (
		!IS_ROCK(tmpmap[current_region.y1-1][current_region.x1-1]) ||
		!IS_ROCK(tmpmap[current_region.y2+1][current_region.x1-1]) ||
		!IS_ROCK(tmpmap[current_region.y1-1][current_region.x2+1]) ||
		!IS_ROCK(tmpmap[current_region.y2+1][current_region.x2+1])) {
				Sprintf(ebuf,
				"NonRock edge in room (%02d,%02d,%02d,%02d)?!",
					current_region.x1, current_region.y1,
					current_region.x2, current_region.y2);
				yywarning(ebuf);
			    }
			} else if(tmpreg[nreg]->rirreg &&
		!IS_ROOM(tmpmap[current_region.y1][current_region.x1])) {
			    char ebuf[60];
			    Sprintf(ebuf,
				    "Rock in irregular room (%02d,%02d)?!",
				    current_region.x1, current_region.y1);
			    yyerror(ebuf);
			}
			nreg++;
			if (nreg >= MAX_OF_TYPE) {
				yyerror("Too many regions in mazepart!");
				nreg--;
			}
		  }
#line 3508 "y.tab.c"
    break;

  case 193: /* altar_detail: ALTAR_ID ':' coordinate ',' alignment ',' altar_type  */
#line 1520 "lev_comp.y"
                  {
			tmpaltar[naltar] = New(altar);
			tmpaltar[naltar]->x = current_coord.x;
			tmpaltar[naltar]->y = current_coord.y;
			tmpaltar[naltar]->align = (yyvsp[-2].i);
			tmpaltar[naltar]->shrine = (yyvsp[0].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Altar");
			naltar++;
			if (naltar >= MAX_OF_TYPE) {
				yyerror("Too many altars in room or mazepart!");
				naltar--;
			}
		  }
#line 3528 "y.tab.c"
    break;

  case 194: /* gold_detail: GOLD_ID ':' amount ',' coordinate  */
#line 1538 "lev_comp.y"
                  {
			tmpgold[ngold] = New(gold);
			tmpgold[ngold]->x = current_coord.x;
			tmpgold[ngold]->y = current_coord.y;
			tmpgold[ngold]->amount = (yyvsp[-2].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Gold");
			ngold++;
			if (ngold >= MAX_OF_TYPE) {
				yyerror("Too many golds in room or mazepart!");
				ngold--;
			}
		  }
#line 3547 "y.tab.c"
    break;

  case 195: /* engraving_detail: ENGRAVING_ID ':' coordinate ',' engraving_type ',' string  */
#line 1555 "lev_comp.y"
                  {
			tmpengraving[nengraving] = New(engraving);
			tmpengraving[nengraving]->x = current_coord.x;
			tmpengraving[nengraving]->y = current_coord.y;
			tmpengraving[nengraving]->engr.str = (yyvsp[0].map);
			tmpengraving[nengraving]->etype = (yyvsp[-2].i);
			if (!in_room)
			    check_coord(current_coord.x, current_coord.y,
					"Engraving");
			nengraving++;
			if (nengraving >= MAX_OF_TYPE) {
			    yyerror("Too many engravings in room or mazepart!");
			    nengraving--;
			}
		  }
#line 3567 "y.tab.c"
    break;

  case 197: /* monster_c: RANDOM_TYPE  */
#line 1574 "lev_comp.y"
                  {
			(yyval.i) = - MAX_REGISTERS - 1;
		  }
#line 3575 "y.tab.c"
    break;

  case 200: /* object_c: RANDOM_TYPE  */
#line 1582 "lev_comp.y"
                  {
			(yyval.i) = - MAX_REGISTERS - 1;
		  }
#line 3583 "y.tab.c"
    break;

  case 203: /* m_name: RANDOM_TYPE  */
#line 1590 "lev_comp.y"
                  {
			(yyval.map) = (char *) 0;
		  }
#line 3591 "y.tab.c"
    break;

  case 205: /* o_name: RANDOM_TYPE  */
#line 1597 "lev_comp.y"
                  {
			(yyval.map) = (char *) 0;
		  }
#line 3599 "y.tab.c"
    break;

  case 206: /* trap_name: string  */
#line 1603 "lev_comp.y"
                  {
			int token = get_trap_type((yyvsp[0].map));
			if (token == ERR)
				yyerror("Unknown trap type!");
			(yyval.i) = token;
			Free((yyvsp[0].map));
		  }
#line 3611 "y.tab.c"
    break;

  case 208: /* room_type: string  */
#line 1614 "lev_comp.y"
                  {
			int token = get_room_type((yyvsp[0].map));
			if (token == ERR) {
				yywarning("Unknown room type!  Making ordinary room...");
				(yyval.i) = OROOM;
			} else
				(yyval.i) = token;
			Free((yyvsp[0].map));
		  }
#line 3625 "y.tab.c"
    break;

  case 210: /* prefilled: %empty  */
#line 1627 "lev_comp.y"
                  {
			(yyval.i) = 0;
		  }
#line 3633 "y.tab.c"
    break;

  case 211: /* prefilled: ',' FILLING  */
#line 1631 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[0].i);
		  }
#line 3641 "y.tab.c"
    break;

  case 212: /* prefilled: ',' FILLING ',' BOOLEAN  */
#line 1635 "lev_comp.y"
                  {
			(yyval.i) = (yyvsp[-2].i) + ((yyvsp[0].i) << 1);
		  }
#line 3649 "y.tab.c"
    break;

  case 216: /* coordinate: RANDOM_TYPE  */
#line 1644 "lev_comp.y"
                  {
			current_coord.x = current_coord.y = -MAX_REGISTERS-2;
		  }
#line 3657 "y.tab.c"
    break;

  case 223: /* alignment: RANDOM_TYPE  */
#line 1660 "lev_comp.y"
                  {
			(yyval.i) = - MAX_REGISTERS - 1;
		  }
#line 3665 "y.tab.c"
    break;

  case 226: /* p_register: P_REGISTER '[' INTEGER ']'  */
#line 1670 "lev_comp.y"
                  {
			if ( (yyvsp[-1].i) >= MAX_REGISTERS )
				yyerror("Register Index overflow!");
			else {
				current_coord.x = -1;
				current_coord.y = - (yyvsp[-1].i) - 1;
			}
		  }
#line 3678 "y.tab.c"
    break;

  case 227: /* p_register: P_REGISTER '[' INTEGER ']' '[' INTEGER ']'  */
#line 1679 "lev_comp.y"
                  {
			if ( (yyvsp[-4].i) >= MAX_REGISTERS || (yyvsp[-1].i) >= MAX_REGISTERS )
				yyerror("Register Index overflow!");
			else {
				current_coord.x = - (yyvsp[-4].i) - 1;
				current_coord.y = - (yyvsp[-1].i) - 1;
			}
		  }
#line 3691 "y.tab.c"
    break;

  case 228: /* r_register: R_REGISTER '[' INTEGER ']'  */
#line 1690 "lev_comp.y"
                  {
			if ( (yyvsp[-1].i) < 0 || (yyvsp[-1].i) >= nrndlreg )
				yyerror("Register Index overflow!");
			else {
				current_coord.x = -MAX_REGISTERS-1;
				current_coord.y = - (yyvsp[-1].i) - 1;
			}
		  }
#line 3704 "y.tab.c"
    break;

  case 229: /* o_register: O_REGISTER '[' INTEGER ']'  */
#line 1701 "lev_comp.y"
                  {
			if ( (yyvsp[-1].i) >= MAX_REGISTERS )
				yyerror("Register Index overflow!");
			else
				(yyval.i) = - (yyvsp[-1].i) - 1;
		  }
#line 3715 "y.tab.c"
    break;

  case 230: /* m_register: M_REGISTER '[' INTEGER ']'  */
#line 1710 "lev_comp.y"
                  {
			if ( (yyvsp[-1].i) >= MAX_REGISTERS )
				yyerror("Register Index overflow!");
			else
				(yyval.i) = - (yyvsp[-1].i) - 1;
		  }
#line 3726 "y.tab.c"
    break;

  case 231: /* a_register: A_REGISTER '[' INTEGER ']'  */
#line 1719 "lev_comp.y"
                  {
			if ( (yyvsp[-1].i) >= 3 )
				yyerror("Register Index overflow!");
			else
				(yyval.i) = - (yyvsp[-1].i) - 1;
		  }
#line 3737 "y.tab.c"
    break;

  case 233: /* place: NONE  */
#line 1729 "lev_comp.y"
                  {
			current_coord.x = (char)-1;
			current_coord.y = (char)-1;
		  }
#line 3746 "y.tab.c"
    break;

  case 234: /* monster: CHAR  */
#line 1736 "lev_comp.y"
                  {
			if (check_monster_char((char) (yyvsp[0].i)))
				(yyval.i) = (yyvsp[0].i) ;
			else {
				yyerror("Unknown monster class!");
				(yyval.i) = ERR;
			}
		  }
#line 3759 "y.tab.c"
    break;

  case 235: /* object: CHAR  */
#line 1747 "lev_comp.y"
                  {
			char c = (yyvsp[0].i);
			if (check_object_char(c))
				(yyval.i) = c;
			else {
				yyerror("Unknown char class!");
				(yyval.i) = ERR;
			}
		  }
#line 3773 "y.tab.c"
    break;

  case 239: /* chance: %empty  */
#line 1766 "lev_comp.y"
                  {
			(yyval.i) = 100;	/* default is 100% */
		  }
#line 3781 "y.tab.c"
    break;

  case 240: /* chance: PERCENT  */
#line 1770 "lev_comp.y"
                  {
			if ((yyvsp[0].i) <= 0 || (yyvsp[0].i) > 100)
			    yyerror("Expected percentile chance.");
			(yyval.i) = (yyvsp[0].i);
		  }
#line 3791 "y.tab.c"
    break;

  case 243: /* coord: '(' INTEGER ',' INTEGER ')'  */
#line 1782 "lev_comp.y"
                  {
			if (!in_room && !init_lev.init_present &&
			    ((yyvsp[-3].i) < 0 || (yyvsp[-3].i) > (int)max_x_map ||
			     (yyvsp[-1].i) < 0 || (yyvsp[-1].i) > (int)max_y_map))
			    yyerror("Coordinates out of map range!");
			current_coord.x = (yyvsp[-3].i);
			current_coord.y = (yyvsp[-1].i);
		  }
#line 3804 "y.tab.c"
    break;

  case 244: /* region: '(' INTEGER ',' INTEGER ',' INTEGER ',' INTEGER ')'  */
#line 1793 "lev_comp.y"
                  {
/* This series of if statements is a hack for MSC 5.1.  It seems that its
   tiny little brain cannot compile if these are all one big if statement. */
			if ((yyvsp[-7].i) < 0 || (yyvsp[-7].i) > (int)max_x_map)
				yyerror("Region out of map range!");
			else if ((yyvsp[-5].i) < 0 || (yyvsp[-5].i) > (int)max_y_map)
				yyerror("Region out of map range!");
			else if ((yyvsp[-3].i) < 0 || (yyvsp[-3].i) > (int)max_x_map)
				yyerror("Region out of map range!");
			else if ((yyvsp[-1].i) < 0 || (yyvsp[-1].i) > (int)max_y_map)
				yyerror("Region out of map range!");
			current_region.x1 = (yyvsp[-7].i);
			current_region.y1 = (yyvsp[-5].i);
			current_region.x2 = (yyvsp[-3].i);
			current_region.y2 = (yyvsp[-1].i);
		  }
#line 3825 "y.tab.c"
    break;


#line 3829 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1811 "lev_comp.y"


/*lev_comp.y*/
