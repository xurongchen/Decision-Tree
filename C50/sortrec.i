#ifndef __SORTREC_I__
#define __SORTREC_I__
typedef enum _att_type {
    MYUNKNOW = 0,
    MYCONT,
    MYDISC,
    MYCONTRANGE,
    MYSTRING
}AttType;
typedef  int	ClassNo;

#ifdef USEDOUBLE
typedef	 double	ContValue;	/* continuous attribute value */
#define	 PREC	14		/* precision */
#else
typedef	 float	ContValue;	/* continuous attribute value */
#define	 PREC	 7		/* precision */
#endif

typedef	 struct _sort_rec
{
    ContValue	V;
    ClassNo	C;
    float	W;
    AttType T;
}SortRec;


#endif