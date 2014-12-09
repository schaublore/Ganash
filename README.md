Ganash
======

The Ganash.Display.Graphics is a convenience C library that uses the cairo 2D library for drawing.

Ganash.Display.Graphics contains a set of objects that you can use to models a vector drawing.
It support Gradients and Pattern images... Each of these methods use a cairo context.
The following are among those helper functions provided for ease of use: to_context(), to_surface().

Major Objects :

+----GraphicsPath
+----GraphicsFill
+----GraphicsStroke
+----GraphicsPaint

Source Object:

+----GraphicsSource
+----GraphicsSolid
+----GraphicsGradient
      +----GraphicsGradientLinear
      +----GraphicsGradientRadial
      +----GraphicsGradientMesh

Surface Object:

+----GraphicsSurface
+----GraphicsImage
