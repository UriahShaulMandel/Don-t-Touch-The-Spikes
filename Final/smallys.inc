.686
.code
getRandomNumberIn Proc min: DWORD , max: DWORD
;made by itamar
	push ecx
	push edx
	xor edx,edx
	rdrand eax
	mov ecx,max
	sub ecx,min
	idiv ecx
	add edx,min
	mov eax,edx
	mov eax,edx
	pop edx
	pop ecx
	ret

getRandomNumberIn ENDP

bigger proc First:DWORD,Second:DWORD ;returns the bigger number in eax and the smaller one in ebx
mov eax,First
cmp eax,Second
jae FirstIsBigger
jl SecondIsBigger
SecondIsBigger:
mov ebx,First
mov eax,Second
ret
FirstIsBigger:
mov eax,First
mov ebx,Second
ret
bigger endp

jump proc
cmp player.y1,300
jl rett
mov player.YSpeed,Jump_Rate
rett:
ret
jump endp
DotinBetween proc START:dword,FINISH:dword,X:dword
push ebx
mov ebx,START
cmp X,ebx
jl break
mov ebx,FINISH
cmp X,ebx
ja break
pop ebx
mov eax,1
ret
break:
pop ebx
mov eax,0
ret
DotinBetween endp

LineinBetween proc START:dword,FINISH:dword,x1:dword,x2:dword
 pusha
invoke DotinBetween,START,FINISH,x1
cmp eax,1
je yes
invoke DotinBetween,x1,x2,START
cmp eax,1
je yes
invoke DotinBetween,START,FINISH,x1
cmp eax,1
je yes
invoke DotinBetween,START,FINISH,x2
cmp eax,1
je yes
jmp nope
yes:
popa
mov eax,1
ret
nope:
popa
mov eax,0
ret
LineinBetween endp

recCallDec proc FirstX1:DWORD,FirstY1:DWORD,SecondX1:dword,SecondY1:dword,FirstX2:DWORD,FirstY2:DWORD,SecondX2:dword,SecondY2:dword
pusha
invoke LineinBetween,FirstX1,SecondX1,FirstX2,SecondX2
cmp eax,0
je nope
invoke LineinBetween,FirstY1,SecondY1,FirstY2,SecondY2
cmp eax,0
je nope
jmp yes

yes:
popa
mov eax,1
ret
nope:
popa
mov eax,0
ret
recCallDec endp


ai2 proc
cmp player.y2,950
ja yes
cmp GoRight,1
je checkHeightX2
cmp GoRight,0
jne rettt
jmp checkHeightX1

checkHeightX2:
cmp player.x2,1850
ja rettt
checkrspike0:
mov ebx, player.y1
sub ebx,rspike0.y2
cmp ebx,accu 
jl checkAbover0
jmp nextrspike0
checkAbover0:
cmp ebx,-accu
ja yes
jmp nextrspike0
nextrspike0:

checkrspike1:
mov ebx, player.y1
sub ebx,rspike1.y2
cmp ebx,accu
jl checkAbover1
jmp nextrspike1
checkAbover1:
cmp ebx,-accu
ja yes
jmp nextrspike1
nextrspike1:

checkrspike2:
mov ebx, player.y1
sub ebx,rspike2.y2
cmp ebx,accu 
jl checkAbover2
jmp nextrspike2
checkAbover2:
cmp ebx,-accu
ja yes
jmp nextrspike2
nextrspike2:

checkrspike3:
mov ebx, player.y1
sub ebx,rspike3.y2
cmp ebx,accu
jl checkAbover3
jmp nextrspike3
checkAbover3:
cmp ebx,-accu
ja yes
jmp nextrspike3
nextrspike3:
jmp rettt




checkHeightX1:
cmp player.x1,20
jl rettt
checklspike0:
mov ebx, player.y1
sub ebx,lspike0.y2
cmp ebx,accu 
jl checkAbover0l
jmp nextrspike0l
checkAbover0l:
cmp ebx,-accu
ja yes
jmp nextrspike0l
nextrspike0l:

checkrspike1l:
mov ebx, player.y1
sub ebx,lspike1.y2
cmp ebx,accu
jl checkAbover1l
jmp nextrspike1
checkAbover1l:
cmp ebx,-accu
ja yes
jmp nextrspike1l
nextrspike1l:

checkrspike2l:
mov ebx, player.y1
sub ebx,lspike2.y2
cmp ebx,accu 
jl checkAbover2l
jmp nextrspike2l
checkAbover2l:
cmp ebx,-accu
ja yes
jmp nextrspike2l
nextrspike2l:

checkrspike3l:
mov ebx, player.y1
sub ebx,lspike3.y2
cmp ebx,accu
jl checkAbover3l
jmp nextrspike3l
checkAbover3l:
cmp ebx,-accu
ja yes
jmp nextrspike3l
nextrspike3l:
jmp rettt












yes:
invoke jump
rettt:
ret
ai2 endp


