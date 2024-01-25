import pyvista as pv
import numpy as np
import meshio

file_name = "./sphere.obj"

# Read mesh
pv_mesh = pv.read(file_name)

# Oversampling the mesh to make it look smoother
subdivision = 3
pv_mesh_oversampled = pv_mesh.subdivide(subdivision)

# save oversampled mesh to .obj file
file_name_oversampled = "./sphere_oversampled.obj"

# Convert PyVista mesh to meshio mesh
meshio_mesh = meshio.Mesh(pv_mesh_oversampled.points, {'triangle': pv_mesh_oversampled.faces.reshape(-1, 4)[:, 1:]})

# Save meshio mesh to .obj file
meshio.write(file_name_oversampled, meshio_mesh)


# Normal Vectors
normals = pv_mesh.point_normals

# Curvature
k1 = pv_mesh.curvature(curv_type='maximum')
k2 = pv_mesh.curvature(curv_type='minimum')
curv = np.maximum(k1, k2)
cmin = np.percentile(curv, 8)
cmax = np.percentile(curv, 95)

# Create a multi-plotter object
plotter = pv.Plotter(shape=(2, 2), window_size=(1800, 1000))

# Add the original mesh to the first subplot
plotter.subplot(0, 0)
plotter.add_mesh(pv_mesh, color="lightblue")
plotter.add_title("Original Mesh", font_size=10)

# Add the oversampled mesh to the second subplot
plotter.subplot(0, 1)
plotter.add_mesh(pv_mesh_oversampled, color="lightblue")
plotter.add_title("Oversampled Mesh", font_size=10)

# Add the normal vectors to the third subplot
plotter.subplot(1, 0)
plotter.add_mesh(pv_mesh, color="lightblue")
plotter.add_arrows(pv_mesh.points, normals, mag=0.05, color='lightblue')
plotter.add_title("Normal Vectors", font_size=10)

# Add the curvature to the fourth subplot
plotter.subplot(1, 1)
plotter.add_mesh(pv_mesh, cmap="bwr", clim=[cmin, cmax], scalars=curv)
plotter.add_title("Curvature", font_size=10)

plotter.show()

# just plot normal vectors
plotter = pv.Plotter()
plotter.add_mesh(pv_mesh, color="lightblue")
plotter.add_arrows(pv_mesh.points, normals, mag=0.05, color='lightblue')
plotter.add_title("Normal Vectors", font_size=10)
plotter.show()

# just plot curvature
plotter = pv.Plotter()
plotter.add_mesh(pv_mesh, cmap="bwr", clim=[cmin, cmax], scalars=curv)
plotter.add_title("Curvature", font_size=10)
plotter.show()