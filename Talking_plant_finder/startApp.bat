@echo off
call config.bat
del utt*.wav
%EXECAPP% -package %PKGHOME% client.AllowBargeIn lm.Addresses=localhost client.TTSAddresses=localhost 
# %EXECAPP% -package %PKGHOME% client.AllowBargeIn lm.Addresses=localhost rm.Addresses=localhost client.TTSAddresses=localhost
# %EXECAPP% -package %PKGHOME% client.AllowBargeIn lm.Addresses=localhost rm.Addresses=localhost client.TTSAddresses=localhost audio.OutputVolume=100
# %EXECAPP% -package %PKGHOME% -dbprovider_dg fs -dbroot_dg %APPHOME% -dbclass_dg dgdb -dbname_dg client.AllowBargeIn rcapp lm.Addresses=localhost rm.Addresses=localhost tts.ResourceName="volume 100"
@echo on
pause
