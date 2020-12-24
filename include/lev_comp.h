/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 224 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
