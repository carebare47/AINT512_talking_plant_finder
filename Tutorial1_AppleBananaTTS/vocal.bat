call config.bat
COLOR 2F
%VOCALIZER%\bin\win32\vocalizer.exe lm.Addresses=localhost:8471 -voice clairekingston
# %VOCALIZER%\bin\win32\vocalizer.exe lm.Addresses=localhost:8471 rm.Addresses=localhost -voice clairekingston
# D:\Nuance85\Vocalizer4.0\bin\win32\vocalizer.exe lm.Addresses=localhost:8471 rm.Addresses=localhost -voice clairekingston -pruning 250 -encoding alaw -volume 50 -text_type plain -num_channels 1
pause

