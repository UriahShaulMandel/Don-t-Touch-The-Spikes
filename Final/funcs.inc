
include smallys.inc
.686 
.code

;;draw Digit and DrawNumber ~Uriah Shaul Mandel
drawDigit proc digit:dword,x:dword,y:dword
pusha
cmp digit,0
jne after0
invoke drd_imageDraw,offset ImgDatabase.num0,x,y
after0:
cmp digit,1
jne after1
invoke drd_imageDraw,offset ImgDatabase.num1,x,y
after1:
cmp digit,2
jne after2
invoke drd_imageDraw,offset ImgDatabase.num2,x,y
after2:
cmp digit,3
jne after3
invoke drd_imageDraw,offset ImgDatabase.num3,x,y
after3:
cmp digit,4
jne after4
invoke drd_imageDraw,offset ImgDatabase.num4,x,y
after4:
cmp digit,5
jne after5
invoke drd_imageDraw,offset ImgDatabase.num5,x,y
after5:
cmp digit,6
jne after6
invoke drd_imageDraw,offset ImgDatabase.num6,x,y
after6:
cmp digit,7
jne after7
invoke drd_imageDraw,offset ImgDatabase.num7,x,y
after7:
cmp digit,8
jne after8
invoke drd_imageDraw,offset ImgDatabase.num8,x,y
after8:
cmp digit,9
jne after9
invoke drd_imageDraw,offset ImgDatabase.num9,x,y
after9:
popa
ret
drawDigit endp

drawNumber proc number:dword,x:dword,y:dword
pusha
xor edx,edx
mov eax,number
mov ebx,10
div ebx
mov ecx,eax
cmp eax,0
jne yes
no:
invoke drawDigit,number,x,y
add x,LETTER_WIDTH
popa
mov eax,x
ret
yes:
invoke drawNumber,ecx,x,y
invoke drawDigit,edx,eax,y
add x,LETTER_WIDTH
popa
mov eax,x
ret
drawNumber endp



drawSpikes proc
invoke drd_imageDraw,offset ImgDatabase.spike2,	rspike0.x2,	rspike0.y1
invoke drd_imageDraw,offset ImgDatabase.spike2,	rspike1.x2,	rspike1.y1
invoke drd_imageDraw,offset ImgDatabase.spike2,	rspike2.x2,	rspike2.y1
invoke drd_imageDraw,offset ImgDatabase.spike2,	rspike3.x2,	rspike3.y1

invoke drd_imageDraw,offset ImgDatabase.spike,	lspike0.x1,	lspike0.y1
invoke drd_imageDraw,offset ImgDatabase.spike,	lspike1.x1,	lspike1.y1
invoke drd_imageDraw,offset ImgDatabase.spike,	lspike2.x1,	lspike2.y1
invoke drd_imageDraw,offset ImgDatabase.spike,	lspike3.x1,	lspike3.y1

ret
drawSpikes endp

changeLeftSpikes proc
;mov spike 0
invoke getRandomNumberIn,SPIKE_MIN_Y,SPIKE_MAX_Y
mov lspike0.y1,eax
mov lspike0.y2,eax
add lspike0.y2,SPIKE_HEIGHT
mov lspike0.x1,0
mov lspike0.x2,SPIKE_WIDTH
;mov spike 0

;mov spike 1
invoke getRandomNumberIn,SPIKE_MIN_Y,SPIKE_MAX_Y
mov lspike1.y1,eax
mov lspike1.y2,eax
add lspike1.y2,SPIKE_HEIGHT
mov lspike1.x1,0
mov lspike1.x2,SPIKE_WIDTH
;mov spike 1

;mov spike 2
invoke getRandomNumberIn,SPIKE_MIN_Y,SPIKE_MAX_Y
mov lspike2.y1,eax
mov lspike2.y2,eax
add lspike2.y2,SPIKE_HEIGHT
mov lspike2.x1,0
mov lspike2.x2,SPIKE_WIDTH
;mov spike 2

;mov spike 3
invoke getRandomNumberIn,SPIKE_MIN_Y,SPIKE_MAX_Y
mov lspike3.y1,eax
mov lspike3.y2,eax
add lspike3.y2,SPIKE_HEIGHT
mov lspike3.x1,0
mov lspike3.x2,SPIKE_WIDTH
;mov spike 3

ret
changeLeftSpikes endp

changeRightSpikes proc
;mov spike 0
invoke getRandomNumberIn,SPIKE_MIN_Y,SPIKE_MAX_Y
mov rspike0.y1,eax
mov rspike0.y2,eax
add rspike0.y2,SPIKE_HEIGHT
mov rspike0.x1,WINDOW_WIDTH
mov rspike0.x2,WINDOW_WIDTH
sub rspike0.x2,SPIKE_WIDTH
;mov spike 0


;mov spike 1
invoke getRandomNumberIn,SPIKE_MIN_Y,SPIKE_MAX_Y
mov rspike1.y1,eax
mov rspike1.y2,eax
add rspike1.y2,SPIKE_HEIGHT
mov rspike1.x1,WINDOW_WIDTH
mov rspike1.x2,WINDOW_WIDTH
sub rspike1.x2,SPIKE_WIDTH
;mov spike 1


;mov spike 2
invoke getRandomNumberIn,SPIKE_MIN_Y,SPIKE_MAX_Y
mov rspike2.y1,eax
mov rspike2.y2,eax
add rspike2.y2,SPIKE_HEIGHT
mov rspike2.x1,WINDOW_WIDTH
mov rspike2.x2,WINDOW_WIDTH
sub rspike2.x2,SPIKE_WIDTH
;mov spike 2


;mov spike 3
invoke getRandomNumberIn,SPIKE_MIN_Y,SPIKE_MAX_Y
mov rspike3.y1,eax
mov rspike3.y2,eax
add rspike3.y2,SPIKE_HEIGHT
mov rspike3.x1,WINDOW_WIDTH
mov rspike3.x2,WINDOW_WIDTH
sub rspike3.x2,SPIKE_WIDTH
;mov spike 3
ret
changeRightSpikes endp

cler proc
mov restart,0
mov player.x1,100
mov player.y1,500
mov GoRight,1
mov player.YSpeed,-10
mov score,0

mov rspike0.x1,0
mov rspike0.y1,0
mov rspike1.x1,0
mov rspike1.y1,0
mov rspike2.x1,0
mov rspike2.y1,0
mov rspike3.x1,0
mov rspike3.y1,0

mov rspike0.x2,0
mov rspike0.y2,0
mov rspike1.x2,0
mov rspike1.y2,0
mov rspike2.x2,0
mov rspike2.y2,0
mov rspike3.x2,0
mov rspike3.y2,0

mov lspike0.x1,0
mov lspike0.y1,0
mov lspike1.x1,0
mov lspike1.y1,0
mov lspike2.x1,0
mov lspike2.y1,0
mov lspike3.x1,0
mov lspike3.y1,0

mov lspike0.x2,0
mov lspike0.y2,0
mov lspike1.x2,0
mov lspike1.y2,0
mov lspike2.x2,0
mov lspike2.y2,0
mov lspike3.x2,0
mov lspike3.y2,0

invoke drd_imageLoadFile,offset StringDatabase.bird,offset player.img

ret
cler endp

Lost proc
INVOKE PlaySound, offset StringDatabase.fail, NULL,SND_ASYNC
los:
invoke drd_processMessages

invoke drd_imageDraw,offset ImgDatabase.loser,0,0
invoke drawNumber, score,735,389
invoke drd_flip
cmp restart,1
je restartt

jmp los

restartt:
ret
Lost endp

SpikesCollDetector proc
push ebx
mov ebx,player.x1
add ebx,PLAYER_WIDTH
mov player.x2,ebx

mov ebx,player.y1
add ebx,PLAYER_HEIGHT
mov player.y2,ebx
pop ebx

cmp player.y1,84
jl break
cmp player.y2,WINDOW_HEIGHT-84
ja break


invoke recCallDec, player.x1,player.y1,player.x2,player.y2,rspike0.x1,rspike0.y1,rspike0.x2,rspike0.y2
cmp eax,1
je break
invoke recCallDec, player.x1,player.y1,player.x2,player.y2,rspike1.x1,rspike1.y1,rspike1.x2,rspike1.y2
cmp eax,1
je break
invoke recCallDec, player.x1,player.y1,player.x2,player.y2,rspike2.x1,rspike2.y1,rspike2.x2,rspike2.y2
cmp eax,1
je break
invoke recCallDec, player.x1,player.y1,player.x2,player.y2,rspike3.x1,rspike3.y1,rspike3.x2,rspike3.y2
cmp eax,1
je break


invoke recCallDec, player.x1,player.y1,player.x2,player.y2,lspike0.x1,lspike0.y1,lspike0.x2,lspike0.y2
cmp eax,1
je break
invoke recCallDec, player.x1,player.y1,player.x2,player.y2,lspike1.x1,lspike1.y1,lspike1.x2,lspike1.y2
cmp eax,1
je break
invoke recCallDec, player.x1,player.y1,player.x2,player.y2,lspike2.x1,lspike2.y1,lspike2.x2,lspike2.y2
cmp eax,1
je break
invoke recCallDec, player.x1,player.y1,player.x2,player.y2,lspike3.x1,lspike3.y1,lspike3.x2,lspike3.y2
cmp eax,1
je break


ret
break:
invoke Lost
ret
SpikesCollDetector endp

grav proc
pusha
mov ebx ,player.YSpeed
sub player.y1,ebx
sub player.y2,ebx
cmp counter,0
jle do
dec counter
popa
ret
do:
sub player.YSpeed, G
mov counter,counterdef
popa
ret
grav endp

rightnleft proc
cmp player.x1,10
jl goRight
mov ebx,WINDOW_WIDTH
sub ebx,player.img.iwidth
sub ebx,10
cmp player.x1,ebx
ja goLeft
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
cmp GoRight,1
je r
sub player.x1,XMOVINGRATE
ret
r:
add player.x1,XMOVINGRATE

ret
goRight:
mov GoRight,1
inc score
INVOKE PlaySound, offset StringDatabase.ding, NULL,SND_ASYNC

add player.x1,XMOVINGRATE
invoke drd_imageLoadFile,offset StringDatabase.bird,offset player.img
invoke changeRightSpikes
ret;
goLeft:
mov GoRight,0
inc score
INVOKE PlaySound, offset StringDatabase.ding, NULL,SND_ASYNC



sub player.x1,XMOVINGRATE
invoke drd_imageLoadFile,offset StringDatabase.bird2,offset player.img
invoke changeLeftSpikes

ret;
rightnleft endp

KeyHandler proc,k:dword
cmp k,32
jne afterSpace
mov player.YSpeed,Jump_Rate

afterSpace:
cmp k,82
jne afterR
mov restart,1

afterR:

cmp k,80
jne afterP
not eax
not eax
afterP:
ret
KeyHandler endp

upAndDownSpikesInit proc
mov spikeup.x1,0
mov spikeup.x2,WINDOW_WIDTH
mov spikeup.y1,0
mov spikeup.y2,84
ret
upAndDownSpikesInit endp

loadImages proc
invoke drd_imageLoadFile,offset StringDatabase.bird,offset player.img
invoke drd_imageLoadFile,offset StringDatabase.def,offset ImgDatabase.def
invoke drd_imageLoadFile,offset StringDatabase.loser,offset ImgDatabase.loser
invoke drd_imageLoadFile,offset StringDatabase.spike,offset ImgDatabase.spike
invoke drd_imageLoadFile,offset StringDatabase.spike2,offset ImgDatabase.spike2
invoke drd_imageLoadFile,offset StringDatabase.score,offset ImgDatabase.score

invoke drd_imageLoadFile,offset StringDatabase.num0,offset ImgDatabase.num0
invoke drd_imageLoadFile,offset StringDatabase.num1,offset ImgDatabase.num1
invoke drd_imageLoadFile,offset StringDatabase.num2,offset ImgDatabase.num2
invoke drd_imageLoadFile,offset StringDatabase.num3,offset ImgDatabase.num3
invoke drd_imageLoadFile,offset StringDatabase.num4,offset ImgDatabase.num4
invoke drd_imageLoadFile,offset StringDatabase.num5,offset ImgDatabase.num5
invoke drd_imageLoadFile,offset StringDatabase.num6,offset ImgDatabase.num6
invoke drd_imageLoadFile,offset StringDatabase.num7,offset ImgDatabase.num7
invoke drd_imageLoadFile,offset StringDatabase.num8,offset ImgDatabase.num8
invoke drd_imageLoadFile,offset StringDatabase.num9,offset ImgDatabase.num9

ret
loadImages endp


ai proc
cmp player.y2,990
ja yes
cmp GoRight,1
je checkHeightX2
jne checkHeightX1
jmp rettt

checkHeightX2:
cmp player.x2,1850
ja rettt
checkrspike0:
mov ebx, player.y2
sub ebx,rspike0.y1
cmp ebx,accu 
jl checkAbover0
jmp nextrspike0
checkAbover0:
cmp ebx,-accu
ja yes
jmp nextrspike0
nextrspike0:

checkrspike1:
mov ebx, player.y2
sub ebx,rspike1.y1
cmp ebx,accu
jl checkAbover1
jmp nextrspike1
checkAbover1:
cmp ebx,-accu
ja yes
jmp nextrspike1
nextrspike1:

checkrspike2:
mov ebx, player.y2
sub ebx,rspike2.y1
cmp ebx,accu 
jl checkAbover2
jmp nextrspike2
checkAbover2:
cmp ebx,-accu
ja yes
jmp nextrspike2
nextrspike2:

checkrspike3:
mov ebx, player.y2
sub ebx,rspike3.y1
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
mov ebx, player.y2
sub ebx,lspike0.y1
cmp ebx,accu 
jl checkAbover0l
jmp nextrspike0l
checkAbover0l:
cmp ebx,-accu
ja yes
jmp nextrspike0l
nextrspike0l:

checkrspike1l:
mov ebx, player.y2
sub ebx,lspike1.y1
cmp ebx,accu
jl checkAbover1l
jmp nextrspike1
checkAbover1l:
cmp ebx,-accu
ja yes
jmp nextrspike1l
nextrspike1l:

checkrspike2l:
mov ebx, player.y2
sub ebx,lspike2.y1
cmp ebx,accu 
jl checkAbover2l
jmp nextrspike2l
checkAbover2l:
cmp ebx,-accu
ja yes
jmp nextrspike2l
nextrspike2l:

checkrspike3l:
mov ebx, player.y2
sub ebx,lspike3.y1
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
ai endp