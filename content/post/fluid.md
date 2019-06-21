---
title: "Fluid"
date: 2019-06-20T10:21:05+08:00
draft: true
---

- FDM（有限差分法）=用差分近似导数
- FVM（有限体积法）=在单元上积分守恒
- FEM（有限单元法）=在单元上加权残差为零

FDM Finite difference method 有限差分法

FVM Finite volume method 有限体积法

FEM Finite Element Method 有限单元法

水平集方法（Level Set Method） 是一种用于界面追踪和形状建模的数值技术.水平集方法的优点是可以在笛卡尔网格（Cartesian grid）上对演化中的曲线曲面进行数值计算而不必对曲线曲面参数化（这是所谓的欧拉法（Eulerian approach））.）.水平集方法的另一个优点是可以方便的追踪物体的拓扑结构改变.例如当物体的形状一分为二，产生空洞，或者相反的这些操作.所有这些使得水平集方法成为随时间变化的物体建模的有力工具，例如膨胀中的气囊， 掉落到水中的油滴.

数值分析中，交替方向隐式法（Alternating direction implicit method）是有限差分法的一种，用于求解抛物线型偏微分方程或椭圆型偏微分方程。特别适用于求解二维及更高维度的热传导方程与扩散方程。

求解热传导方程在传统上使用Crank-Nicolson方法，该方法较为耗时。ADI的优点在于，每一迭代步中，所求解的方程具有更为简单的结构，因此更易于求解。

In numerical analysis, Stone's method, also known as the strongly implicit procedure or SIP, is an algorithm for solving a sparse linear system of equations. The method uses an incomplete LU decomposition, which approximates the exact LU decomposition, to get an iterative solution of the problem.

ANSYS Fluent uses finite volumes method (FVM) to solve the partial differential equations that define the energy, mass and momentum conservation. 

In CFD, different discretization methods are used:

- Finite Difference(FD)
- Finite Volume(FV)
- Finite Element(FE)
- Spectral Methods
- Boundary Element Method(BEM)
- Particle methods etc

[COMSOL 软件主要采用有限元法解决 CFD 问题](https://cn.comsol.com/blogs/fem-vs-fvm/)

Refer to [What are the differences between CFX and Fluent?](https://studentcommunity.ansys.com/thread/what-are-the-differences-between-cfx-and-fluent/)

- CFX cannot handle a true 2D mesh. It can handle a pseudo-2D mesh which would be a 1 element thickness 3D mesh. While Fluent can handle 2D meshes with no problems.
- Fluent uses a cell-centered approach while CFX uses a vertex-centered approach. The point being is, Fluent is capable of handling polyhedral mesh and cutcell meshes while CFX sticks to just the traditional tetra and hexa mesh topologies.
- CEL (CFX Expression Language) is also used with CFD-Post. So its easier to define algebraic equations and monitor them during your run with CFX. Fluent needs UDFs for customization which can complicate things for beginners. Fluent has post-processing capabilities of its own while CFX needs a dedicated post-processor.
- Mesh Adaption capabilities are weaker in CFX compared to Fluent. In CFX, "Adaptive meshing is available for single domains with no GGI interfaces and limited physics".
- Fluent is continuously worked upon by the engineers at Ansys and there is a significant improvement made with every new release. CFX definitely lacks the focus that Fluent gets from the developers, in my opinion.
- Simulation acceleration with a GPU is possible in Fluent, while it doesn't benefit CFX.