#include "circom.hpp"
#include "calcwit.hpp"
#define NSignals 4
#define NComponents 1
#define NOutputs 0
#define NInputs 3
#define NVars 4
#define NPublic 3
#define __P__ "21888242871839275222246405745257275088548364400416034343698204186575808495617"

/*
Add
*/
void Add_f9aee319a006c9b4(Circom_CalcWit *ctx, int __cIdx) {
    FrElement _sigValue[1];
    FrElement _sigValue_1[1];
    FrElement _sigValue_2[1];
    FrElement _tmp[1];
    int _in_sigIdx_;
    int _offset;
    int _offset_1;
    int _offset_2;
    Circom_Sizes _sigSizes_in;
    _in_sigIdx_ = ctx->getSignalOffset(__cIdx, 0x08b73807b55c4bbeLL /* in */);
    _sigSizes_in = ctx->getSignalSizes(__cIdx, 0x08b73807b55c4bbeLL /* in */);
    /* signal input in[3] */
    /* in[0] === in[1] + in[2] */
    _offset = _in_sigIdx_;
    ctx->multiGetSignal(__cIdx, __cIdx, _offset, _sigValue, 1);
    _offset_1 = _in_sigIdx_ + 1*_sigSizes_in[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_1, _sigValue_1, 1);
    _offset_2 = _in_sigIdx_ + 2*_sigSizes_in[1];
    ctx->multiGetSignal(__cIdx, __cIdx, _offset_2, _sigValue_2, 1);
    Fr_add(_tmp, _sigValue_1, _sigValue_2);
    ctx->checkConstraint(__cIdx, _sigValue, _tmp, "/home/qwe638853/blockchain/circom_puzzles/zero-knowledge-puzzles/Addition/Add.circom:5:4");
    ctx->finished(__cIdx);
}
// Function Table
Circom_ComponentFunction _functionTable[1] = {
     Add_f9aee319a006c9b4
};
