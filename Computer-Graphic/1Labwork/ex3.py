import pyvista as pv

mesh = pv.read("./battlecruiser_silver.obj")

texture = pv.read_texture("./battlecruiser_silver_diff.jpg")

mesh.texture_map_to_plane(inplace=True)

plotter = pv.Plotter()
plotter.add_mesh(mesh, texture=texture)
plotter.show()