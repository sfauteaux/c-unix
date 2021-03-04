{\rtf1\ansi\ansicpg1252\cocoartf2578
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fmodern\fcharset0 Courier;}
{\colortbl;\red255\green255\blue255;\red173\green169\blue32;\red32\green32\blue32;\red88\green118\blue71;
\red191\green100\blue38;\red153\green168\blue186;\red254\green187\blue91;\red109\green109\blue109;\red86\green132\blue173;
}
{\*\expandedcolortbl;;\csgenericrgb\c67843\c66275\c12549;\csgenericrgb\c12549\c12549\c12549;\csgenericrgb\c34510\c46275\c27843;
\csgenericrgb\c74902\c39216\c14902;\csgenericrgb\c60000\c65882\c72941;\csgenericrgb\c99608\c73333\c35686;\csgenericrgb\c42745\c42745\c42745;\csgenericrgb\c33725\c51765\c67843;
}
\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs26 \cf2 \cb3 #include \cf4 <stdio.h>\
\
\cf5 int \cf6 (*pFcn)(\cf5 int, int\cf6 )\cf5 ;\
int \cf7 Add\cf6 (\cf5 int, int\cf6 )\cf5 ;\
int \cf7 Subtract\cf6 (\cf5 int,int\cf6 )\cf5 ;\
int \cf7 Multiply\cf6 (\cf5 int,int\cf6 )\cf5 ;\
int \cf7 Divide\cf6 (\cf5 int,int\cf6 )\cf5 ;\
\
\cf8 /*\
 * Sean Fauteaux\
 * CSCD 240 \
 * Lab 5, Problem 3 "FunctionPointer.c"\
 */\
\
\cf5 int \cf7 main\cf6 () \{\
    \cf5 int \cf6 X\cf5 , \cf6 Y\cf5 , \cf6 operation\cf5 ;\
    \cf6 printf(\cf4 "Enter a number: "\cf6 )\cf5 ;\
    \cf6 scanf(\cf4 " %d"\cf5 , \cf6 &X)\cf5 ;\
    \cf6 printf(\cf4 "Enter another number: "\cf6 )\cf5 ;\
    \cf6 scanf(\cf4 " %d"\cf5 , \cf6 &Y)\cf5 ;\
    \cf6 printf(\cf4 "Enter an operation (0=add, 1=subtract, 2=multiply, 3= Divide ): "\cf6 )\cf5 ;\
    \cf6 scanf(\cf4 " %d"\cf5 , \cf6 &operation)\cf5 ;\
    switch \cf6 (operation) \{\
        \cf5 case \cf9 0\cf6 :\
            pFcn = Add\cf5 ;\
            break;\
        case \cf9 1\cf6 :\
            pFcn = Subtract\cf5 ;\
            break;\
        case \cf9 2\cf6 :\
            pFcn = Multiply\cf5 ;\
            break;\
        case \cf9 3\cf6 :\
            pFcn = Divide\cf5 ;\
            break;\
    \cf6 \}\
    printf(\cf4 "The answer is : %d\cf5 \\n\cf4 "\cf5 , \cf6 pFcn(X\cf5 , \cf6 Y))\cf5 ;\
    return \cf9 0\cf5 ;\
\cf6 \}\
\
\cf5 int \cf7 Add\cf6 (\cf5 int \cf6 a\cf5 , int \cf6 b)\{\
    \cf5 return \cf6 a+b\cf5 ;\
\cf6 \}\
\cf5 int \cf7 Subtract\cf6 (\cf5 int \cf6 a\cf5 ,int \cf6 b)\{\
    \cf5 return \cf6 a-b\cf5 ;\
\cf6 \}\
\cf5 int \cf7 Multiply\cf6 (\cf5 int \cf6 a\cf5 ,int \cf6 b)\{\
    \cf5 return \cf6 a*b\cf5 ;\
\cf6 \}\
\cf5 int \cf7 Divide\cf6 (\cf5 int \cf6 a\cf5 ,int \cf6 b)\{\
    \cf5 return \cf6 a/b\cf5 ;\
\cf6 \}\
}