include \masm32\include\masm32rt.inc
include constants.inc
include drd.inc
includelib drd.lib
include \masm32\include\winmm.inc
includelib \masm32\lib\winmm.lib

include data.inc
include main_funcs.inc

.code
main proc
invoke init
homescreen:
invoke cler

arena:
invoke drd_processMessages
invoke update
invoke draw

invoke Sleep,Sleep_Rate
cmp restart,1
je homescreen
jmp arena
ret
main endp
end main