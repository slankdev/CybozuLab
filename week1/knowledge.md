
# $BCN$i$J$+$C$?$3$H$^$H$a(B

Feb.3 - Feb.5




## $B%a%s%P4X?t$N(Bconst$B%3%l%/%H%M%9(B

$B%a%=%C%I$r(Bconst$B$GDj5A$9$k$H!"$=$N%a%=%C%I$J$$$G$O!"A4$F$N%a%s%PJQ?t$,(Bconst$B$K$J$k!#(B

```
class A {
	int a;
	int b;
	A(int _a, int _b) : a(_a), b(_b) {}
	int func() const {
		return a+b;
	}
};
```

## $B%1%s!&%W!<$N!V%$%s%?!<%U%'!<%9$N;086B'!W(B

 1. $B%$%s%?!<%U%'!<%9$N<BAu$O!"$=$N%a%=%C%I$,<($9$H$&$j$N=hM}$r9T$o$J$1$l$P$J$i$J$$(B
 1. $B%$%s%?!<%U%'!<%9$N<BAu$O!"B>$K4m32$r2C$($F$O$J$i$J$$!#(B
 1. $B%$%s%?!<%U%'!<%9$N<BAu$O!"<+J,$N@UG$$r2L$?$;$J$$>l9g!"$=$N$3$H$r8F$S=P$785$KEA$($J$1$l$P$J$i$J$$(B

$B;0$DL\$NBP=hJ}K!$r0J2<$K<($9!#(B

 1. $B%(%i!<%3!<%I$rJV$9(B ($B$3$l$O(Bc$BE*9M$($+$?(B)
 1. $BNc30$rEj$2$k(B ($B$3$l$r:NMQ$7$F$$$-$?$$(B)
 1. $B%W%m%0%i%`$rDd;_$9$k(B ($B$3$l$O6KNO$5$1$?$$(B)

$B%(%i!<Js9p$NJ}K!$r0l4S$5$;$F!"%I%-%e%a%s%H2=$r$7$F$*$/I,MW$,$"$k(B



## $B%I%-%e%a%s%H2=$K$D$$$F(B

$B:G>.8B%I%-%e%a%s%H$r8+$l$P$&$^$/;H$($k!#%5%s%W%k$KMj$i$:$K;H$($k%i%$%V%i%j$r@_7W$7$F$$$-$?$$!#(B
$B$@$,!":GDc8B$N%I%-%e%a%s%H$OI,MW!#$=$N$h$&$J%I%-%e%a%s%H$N:n@.J}K!$N<jK!(B


## $B%/%i%9@_7W(B

$B7Q>5$OB?3,AX2=$5$;$J$$$h$&$K$9$k!#(B($BB?$/$F$b(B2-3$B$/$i$$(B)
$B$F$3$H$O%W%m%H%3%k$4$H$N%/%i%9$N7Q>5I=8=$OLdBj$,$"$k$N$G$O$J$$$+!#!#(B
is-a$B$OLdBj$"$j$C$]$$$N$G!"(Bhas-a$BE*$J9M$(J}$K$7$^$9$+!#!#!#(B

### $B%a%s%PJQ?t$K$D$$$F(B

$B%W%m%H%3%kMWAG%a%s%PJQ?t$OA4$F(Bprivate$BJQ?t$K$9$k$3$H!#A4$F$NMWAG$KBP$7$F(Bsetter, getter$B$r;HMQ$7$F<BAu$9$k!#(B
***$B%$%s%?!<%U%'!<%9$r$I$N$h$&$K$9$k$+$O$"$H$"$H9M$($F$b$$$$$N$G(B***$B$^$:$OJQ?t$N07$$$J$I$r0BDj$5$;$k!#(B

***$B%"%$%G%#%"(B***

$B%a%s%PJQ?t$r<oN`$4$H(B(bit$BD9!"%"%I%l%9$d%]!<%H(B)$B$K%/%i%9$H$7$F<BAu$7$F!"0MB8$,$"$kMWAG$OFCJL$KM%6x$5$;$k(B


### $B%Q%1%C%H%/%i%9$N<BAuNc(B

```
class packet {
	private:
		/* packet binary datas  */
		/* packet binary length */
	public:
		void*  raw();      /* packet binary datas */
		size_t length();   /* packet binary length */
		bool   correct();  /* is correct packet */
		virtual void summary();
		virtual void info();
		virtual void compile();
};
```



## $B%P%$%HNs$N4IM}$r(Bvector$B$J$I$N2DJQD9$J$b$N$G9T$&$h$&$K$9$k!#(B

$B$3$l$O$^$@%N!<%W%i%s!#(Bvector$B$N;H$$J}$9$iHyL/$J$N$G!#(B





## $BNc30=hM}(B

std::exception$B%/%i%9$r7Q>5$9$l$P?7$?$KNc30%/%i%9$r:n$l$k(B




## $B%3!<%G%#%s%0:nK!(B

$BEv$?$jA0$J$3$H$+$b$7$l$J$$$,!"CN$i$J$+$C$?$3$H$^$H$a!#(B


### $B%3%a%s%H$N=q$-J}(B

```
int Func(int arg0, arg1);
```

$B$3$N$h$&$J4X?t$N%3%a%s%H$N=q$-J}$O$3$&$J$k(B

```
/******************************************
 * Func -- summary...                     *
 *                                        *
 * Arguments                              *
 *     arg0  --  description              *
 *     arg1  --  description              *
 *                                        *
 * Return                                 *
 *     return-variables summary           *
 ******************************************/
```
$B;W$C$?$3$H$@$1$I!"%X%C%@%U%!%$%k$&$^$/=q$1$P!"$3$&$$$&%3%a%s%H$[$H$s$I$$$i$J$/$J$j$=$&!#(B
$B$$$d!"%3%a%s%H$O$"$k$@$1$"$C$?$[$&$,$$$$$N$+$J!#!#$$$d$=$s$J$3$H$J$$$+!#$b$&$o$m$?(B



## $B!V(BC++ Coding Standards$B!W$rFI$s$G(B

$B%M%C%H$GNI=q$H=q$$$F$"$C$F!"$=$l$,%5%$%\%&%:<R$N?^=q$H$7$F$"$C$?$N$G!"$h$s$@!#(B
$B$3$N3+H/$GI,MW$H;W$o$l$k$3$H$r2U>r=q$-$G<($9!#(B

 - $B%3%s%Q%$%k$N7Y9p%l%Y%k$O:G9b$K$7$F3+H/(B
 - $B<B9T;~%(%i!<$h$j!"%3%s%Q%$%k;~%(%i!<$H%j%s%/;~%(%i!<$r4?7^$7$h$&(B
 	- enum 
 	- $B%@%&%s%-%c%9%H(B
 - const$B$r@Q6KE*$K;H$&(B
 - $B$J$k$Y$/6I=jJQ?t(B
 - ***$B%^%8%C%/%J%s%P!<$OHr$1$h$&(B***($B?4$,DK$$!#!#(B)
 - $B0l$D$N4X?t$K0l$D$N;E;v(B
 - $B$I$N$h$&$J%/%i%9$K$9$k$+$rL@3N2=(B
 - $B%a%s%PJQ?t$O(Bprivate$B%a%s%P$K$7$h$&(B
 - ***$BFbIt$N>pJs$r8x3+$7$J$$(B***
 - $B%3%s%9%H%i%/%?$OBeF~$h$j!"=i4|2=$r;H$((B
 - $B%3%s%9%H%i%/%?!"%G%9%H%i%/%?FbIt$+$i2>A[4X?t$r8F$S=P$5$J$$(B
 - $B4pK\%/%i%9$N%G%9%H%i%/%?$O(Bpublic$B2>A[$+!"(Bprotected$BHs2>A[$K$9$k(B
 - $B%G%9%H%i%/%?!"%j%=!<%92rJ|!"(Bswap$B$O7h$7$F<:GT$5$;$J$$(B
 - $B@Q6KE*$K(Bassert$B$r$7$h$&(B($B$3$l$OJLES$G(Bassert$B$K$D$$$F$$$m$$$m;n$=$&(B)
 - $B%(%i!<DLCN$ONc30$r;H$*$&(B
 - $BNc30$OCM$GEj$2$F;2>H$GJaB*$7$h$&(B
 - C$B%9%?%$%k$N%-%c%9%H$O;HMQ$7$J$$!"(BC++$B%9%?%$%k$r;H$((B

$B4X78$J$$$3$H$@$,!"$3$NK\(Bvector$B9%$-$9$.$o$m$?!#(B($B$=$l$@$1JXMx$C$F$3$H$J$N$+$J(B)


## $B!V(BC++$B<BA)%W%m%0%i%_%s%0!W$rFI$s$G(B

$B$+$J$jJ,8|$$K\$@$C$?$N$G!"0lDL$j$9$i8+$k$3$H$b$G$-$F$$$J$$$,!"(B"$B%W%m%0%i%`$N@_7W(B"$B$N$H$3$m$@$1$9$3$7FI$s$@!#(B

 - $B@_7WL\I8(B
	 - $B?.Mj@-(B ($B%/%i%C%7%e$7$J$$%W%m%0%i%`!#$*$+$7$/$J$C$?$i65$($k(B)
	 - $B7P:Q@-(B ($B$3$l$O$"$?$j$^$((B)
	 - $B;H$$$d$9$5(B ($B5!G=DI2C>I8u72$K$J$k$J(B, $B%I%-%e%a%s%H>/$7FI$a$P;H$($k$h$&$K:n$l(B)
 - $B@_7WMWAG(B
	 - $BC1=c$5(B 
	 - $B>pJs$N1#JC(B 
	 - $B3HD%@-(B
	 - $B%F%9%H2DG=(B
	 - $B:FMxMQ@-$HK^MQ@-(B
 - $B@_7W86B'(B
	 - $BA@$C$F$+$i7b$F(B
	 - $B7b$C$F$+$iA@$C$F$OEv$?$i$J$$(B
 - $B%W%m%7%8%c$H%*%V%8%'%/%H$r4oMQ$K;H$$J,$1$k(B

$B9M$($F$+$i%3!<%G%#%s%0$7$m!"$C$F=q$+$l$F$?!#$O$$!#2y$$2~$a$^$9!#(B($B$$$^$^$G%3!<%I=q$-$J$,$i9M$($F$?$+$i$$$m$$$m(B
$B%4%_$@$C$?5-21$"$k!#$"$kDxEY=q$/(B->$B$"!"$3$l$3$3$,$@$a$@(B, $B$N%k!<%W$G$7$?(B)


## $B@_7W>pJs$O$3$&$^$H$a$k(B

$B3F%3%s%]!<%M%s%H$N4X78$r(Bnamespace$B$G<($9!#(B
$B$=$N8e3F%3%s%]!<%M%s%H$N$b$D%/%i%9$J$I$rJ,$1$FNs5s$7$F$$$/!#(B
$B:G=*E*$K$O4X?t%j%9%H$^$G:n@.$r$9$k!#(B




