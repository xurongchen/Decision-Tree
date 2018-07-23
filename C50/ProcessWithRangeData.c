//
// Created by new on 2018/2/26.
//

#include "defns.i"
#include "extern.i"



/*
Assigns in the pointer arguments the number of implications that start at i - implications that end at i.
Only consider those implications that lie entirely between Fp and Lp. Handles implications from right to
left and left to right separately.
*/
void numImplicationsCutAtLeftRightSepWithRange(int i, int Fp, int Lp, struct cmap const *Implications, struct array const *classAttr,
                                               SortRec const *SRect, struct array const *rangeImplications, int rangeCount, int *numRangeImplicationsCutLeft2Right, int *numRangeImplicationsCutRight2Left,int *RangeMap ,int *numImplicationsCutLeft2Right, int *numImplicationsCutRight2Left) {
    int ret = 0;
    //int current;
    *numImplicationsCutLeft2Right -= *numRangeImplicationsCutLeft2Right;
    *numImplicationsCutRight2Left -= *numRangeImplicationsCutRight2Left;
    *numRangeImplicationsCutLeft2Right = 0;
    *numRangeImplicationsCutRight2Left = 0;

    struct array * values = cmap_get (Implications, i);
    int j;
    if (classAttr->entries[i] == 0) { // when this entry is a known class, it should have been propagated
        for (j = 0; j < values->size; j++) {
            assert (values->entries[j] != i);
            if(SRect[i].T != MYCONTRANGE && SRect[values->entries[j]].T != MYCONTRANGE){
                if ((values->entries[j] > i) && (values->entries[j] <= Lp) && classAttr->entries[values->entries[j]] == 0)
                    *numImplicationsCutLeft2Right = *numImplicationsCutLeft2Right + 1;

                else if ((values->entries[j] < i) && (values->entries[j] >= Fp) && classAttr->entries[values->entries[j]] == 0)
                    *numImplicationsCutRight2Left = *numImplicationsCutRight2Left - 1;
            }else{
                if ((values->entries[j] > i) && (values->entries[j] <= Lp) && classAttr->entries[values->entries[j]] == 0)
                    *numRangeImplicationsCutLeft2Right += (int)SRect[i].W *(int)SRect[values->entries[j]].W;
                else if ((values->entries[j] < i) && (values->entries[j] >= Fp) && classAttr->entries[values->entries[j]] == 0)
                    *numImplicationsCutRight2Left = *numImplicationsCutRight2Left - 1;
            }
        }
    }

    values = cmap_rget (Implications, i);

    if (classAttr->entries[i] == 0) {
        for (j = 0; j < values->size; j++) {
            assert (values->entries[j] != i);
            if ((values->entries[j] > i) && (values->entries[j] <= Lp) && classAttr->entries[values->entries[j]] == 0)
                *numImplicationsCutRight2Left = *numImplicationsCutRight2Left + 1;

            else if ((values->entries[j] < i) && (values->entries[j] >= Fp) && classAttr->entries[values->entries[j]] == 0)
                *numImplicationsCutLeft2Right = *numImplicationsCutLeft2Right - 1;
        }
    }


    for(int m = 0; m < rangeCount; ++m){
        i = rangeImplications->entries[m];
        values = cmap_get (Implications, i);
        if (classAttr->entries[i] == 0) { // when this entry is a known class, it should have been propagated
            for (j = 0; j < values->size; j++) {
                assert (values->entries[j] != i);
                if(SRect[i].T == MYCONTRANGE || SRect[values->entries[j]].T == MYCONTRANGE){
                    if ((values->entries[j] > i) && (values->entries[j] <= Lp) && classAttr->entries[values->entries[j]] == 0)
                        *numRangeImplicationsCutLeft2Right += (int)SRect[i].W *(int)SRect[values->entries[j]].W;
                }
            }
        }

        values = cmap_rget (Implications, i);
        if (classAttr->entries[i] == 0) {
            for (j = 0; j < values->size; j++){
                assert (values->entries[j] != i);
                if(SRect[i].T == MYCONTRANGE || SRect[values->entries[j]].T == MYCONTRANGE) {
                    if ((values->entries[j] > i) && (values->entries[j] <= Lp) && classAttr->entries[values->entries[j]] == 0)
                        *numRangeImplicationsCutRight2Left += (int)SRect[i].W *(int)SRect[values->entries[j]].W;

                }
            }
        }
    }
    *numImplicationsCutLeft2Right += *numRangeImplicationsCutLeft2Right;
    *numImplicationsCutRight2Left += *numRangeImplicationsCutRight2Left;
    return;
}


int hasImplicationsWithRangeData(int i,int Fp, int Lp, struct cmap const *Implications, struct array const *classAttr, SortRec const *SRect){
    int ret = 0;


    struct array * values = cmap_get (Implications, i);
    int j;
    if (classAttr->entries[i] == 0) { // when this entry is a known class, it should have been propagated
        for (j = 0; j < values->size; j++) {
            assert (values->entries[j] != i);
            if ((values->entries[j] >= Fp) && (values->entries[j]) <= Lp && classAttr->entries[values->entries[j]] == 0) {
                if (SRect[i].T == MYCONTRANGE || SRect[values->entries[j]].T == MYCONTRANGE) {
                    ret = 1;
                    break;
                }
            }
        }
    }


    if(ret == 0){
        values = cmap_rget (Implications, i);
        if (classAttr->entries[i] == 0) { // when this entry is a known class, it should have been propagated
            for (j = 0; j < values->size; j++) {
                assert (values->entries[j] != i);
                if ((values->entries[j] >= Fp) && (values->entries[j]) <= Lp && classAttr->entries[values->entries[j]] == 0) {
                    if (SRect[i].T == MYCONTRANGE || SRect[values->entries[j]].T == MYCONTRANGE) {
                        ret = 1;
                        break;
                    }
                }
            }
        }
    }


    return ret;
}


// Daniel
int select_rhs_if_lhs_is_positive(int lhs, int rhs) {
    assert (0 <= lhs && lhs <= MaxCase && 0 <= rhs && rhs <= MaxCase);
    assert (Class(Case[lhs]) == DVal(Case[lhs], ClassAtt));
    assert (Class(Case[rhs]) == DVal(Case[rhs], ClassAtt));

    // Consistency check of the sample
    if (Class(Case[lhs]) == 1 && Class(Case[rhs]) == 2) {
        fprintf(Of, "Found inconsistency in sample, exiting");
        exit(1);
    }

    return (Class(Case[lhs]) == 1 && Class(Case[rhs]) == 0);

}

int select_rhs_if_lhs_is_negative(int lhs, int rhs) {
    assert (0 <= lhs && lhs <= MaxCase && 0 <= rhs && rhs <= MaxCase);
    assert (Class(Case[lhs]) == DVal(Case[lhs], ClassAtt));
    assert (Class(Case[rhs]) == DVal(Case[rhs], ClassAtt));

    // Consistency check of the sample
    if (Class(Case[lhs]) == 1 && Class(Case[rhs]) == 2) {
        fprintf(Of, "Found inconsistency in sample, exiting");
        exit(1);
    }

    return (Class(Case[lhs]) == 2 && Class(Case[rhs]) == 0);
}
// End Daniel