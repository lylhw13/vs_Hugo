---
title: "Ffmpeg"
date: 2019-05-16T08:52:40+08:00
draft: true
---

## how to speed up / slow down a video
refer to [wiki how to speed up / slow down a video](https://trac.ffmpeg.org/wiki/How%20to%20speed%20up%20/%20slow%20down%20a%20video)

### Speeding up/slowing down video

- To double the speed of the vedio, this will drop frames:

    `ffmpeg -i input.mkv -filter:v "setpts=0.5*PTS" output.mkv`

- To avoid drop frames, and 4x speed. Here, 120FPS is equal 30FPS * 4 :

    `ffmpeg -i input.mkv -r 120 -filter:v "setpts=0.25*PTS" output.mkv`

- To Slow down speed, use a multiplier greatr than 1:
    
    `ffmpeg -i input.mkv -filter:v "setpts=2.0*PTS" output.mkv`

#### Smooth:
- You can smooth out slow/fast video with the ​minterpolate video filter. This is also known as "motion interpolation" or "optical flow".

   `fmpeg -i input.mkv -filter:v "minterpolate='mi_mode=mci:mc_mode=aobmc:vsbmc=1:fps=120'" output.mkv`