include funcs.inc
.code

init proc
invoke upAndDownSpikesInit
invoke drd_init,WINDOW_WIDTH,WINDOW_HEIGHT,IS_WINDOW_FULLSCREEN
invoke drd_setKeyHandler,offset KeyHandler
invoke loadImages
ret
init ENDP

draw proc 
invoke drd_imageDraw,offset ImgDatabase.def,0,0
invoke drawSpikes
invoke drd_imageDraw,offset player.img,player.x1,player.y1

invoke drawNumber,score,100,100

invoke drd_flip
ret
draw endp

update proc
invoke grav
invoke rightnleft
invoke SpikesCollDetector
ret
update endp

