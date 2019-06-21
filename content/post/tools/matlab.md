---
title: "Matlab"
date: 2019-06-20T09:19:19+08:00
draft: true
---

- 符号 `...` 可用于连接两行
- 符号 `%` 用于注释

```matlab
x_data = [  0.,   0.,   0.,   0.,   0.,  25.,  25.,  25.,  25.,  25., ...
    50., 50.,  50.,  50.,  50.,  75.,  75.,  75.,  75.,  75., ...
    100., 100., 100., 100., 100.];
    
xT = transpose(x_data);            % 转置

sf = fit([xT, yT],zT,'poly33');         % fit a polynomial surface of degree 3 in x and degree 3 in y.

disp(sf);          % display

plot(sf,[xT,yT],zT);            % plot sf surface and the point of xT, yT, zT
plot(sf);           % only plot sf surface

new_Z = sf(xT, yT);         % generate z value of sf in x and y
fprintf("%f,\n",new_Z);            % print in user format
```

# some wed pages for matlab

- [Fit curve or surface to data](https://ww2.mathworks.cn/help/curvefit/fit.html)