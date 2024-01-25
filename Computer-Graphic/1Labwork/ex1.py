import open3d as o3d
import pyvista as pv
import fast_simplification as fs
from utils import pcd_processing as pcdp
import meshio
import os

"""
Student: BI12-076 Mai Hai Dang
ID % 51 = 25 -> head_part09.pcd
"""

file_path = "./head_part09.pcd"

if os.path.isfile(file_path):
    print(f"File {file_path} exists.")
else:
    print(f"File {file_path} does not exist.")

pcd_data = pcdp.read_pcd("./head_part09.pcd")
print(pcd_data)

mesh = pcdp.convert_pcd_to_mesh(pcd_data)

# Take care of non-manifold edges
mesh = mesh.remove_non_manifold_edges()

# Save mesh to .obj file
file_name_original = "./head_part09_original.obj"

o3d.io.write_triangle_mesh(file_name_original, mesh)

# Read mesh
pv_mesh = pv.read(file_name_original)

# Simplify mesh
pv_mesh_simplified = fs.simplify_mesh(pv_mesh, target_reduction=0.9)

# Save simplified mesh to .obj file
file_name_simplified = "./head_part09_simplified.obj"

# Convert PyVista mesh to meshio mesh
meshio_mesh = meshio.Mesh(pv_mesh_simplified.points, {'triangle': pv_mesh_simplified.faces.reshape(-1, 4)[:, 1:]})

# Save meshio mesh to .obj file
meshio.write(file_name_simplified, meshio_mesh)

# Create a multi-plotter object
plotter = pv.Plotter(shape=(1, 2), window_size=(1800, 1000))

plotter.subplot(0, 0)
plotter.add_mesh(pv_mesh, color="white", show_edges=True)
plotter.add_text("Original Mesh", font_size=10, color="black")

plotter.subplot(0, 1)
plotter.add_mesh(pv_mesh_simplified, color="white", show_edges=True)
plotter.add_text("Simplified Mesh", font_size=10, color="black")

plotter.show()
