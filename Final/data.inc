include dataBASE.inc
include structs.inc
.data
StringDatabase StringDatabaseStruct<> 
ImgDatabase ImgDatabaseStruct<>

MovingRekaTmp dword 700
player PLAYERSTRUCT<>
colorString dword 0
color dword 0
counter dword 10
GoRight byte 1

score dword 0
restart byte 0

lspike0 SPIKE<>
lspike1 SPIKE<>
lspike2 SPIKE<>
lspike3 SPIKE<>

rspike0 SPIKE<>
rspike1 SPIKE<>
rspike2 SPIKE<>
rspike3 SPIKE<>

spikeup SPIKE<>
spikedown SPIKE<>

