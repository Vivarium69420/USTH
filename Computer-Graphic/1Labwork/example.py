import open3d as o3d
import pyvista as pv
import numpy as np
import fast_simplification as fs
import os

file_path = "./brick_part01.pcd"

if os.path.isfile(file_path):
    print(f"File {file_path} exists.")
else:
    print(f"File {file_path} does not exist.")

def read_pcd(FILE_NAME):
    # Try open and read the FILE_NAME
    try:
        pcd = o3d.io.read_point_cloud(FILE_NAME, format="xyzn")
        return pcd
    except:
        print("Couldn't read file")


pcd_data = read_pcd("./brick_part01.pcd")
print(pcd_data)


def convert_pcd_to_mesh(pcd):
    try:
        mesh, densities = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(
            pcd, depth=7
        )  # depth=9
        return mesh
    except:
        print("Invalid Data...")


mesh = convert_pcd_to_mesh(pcd_data)

# Take care of non-manifold edges
mesh = mesh.remove_non_manifold_edges()

# Save mesh to .obj file
file_name = "./brick_part01.obj"

o3d.io.write_triangle_mesh(file_name, mesh)

# Read mesh
pv_mesh = pv.read(file_name)

# Simplify mesh
pv_mesh_simplified = fs.simplify_mesh(pv_mesh, target_reduction=0.9)

# Oversampling the mesh to make it look smoother
subdivision = 2
pv_mesh_oversampled = pv_mesh.subdivide(subdivision)

# ====== Mesh Alteration ====== #
"""
# Create a multi-plotter object
plotter = pv.Plotter(shape=(2, 2), window_size=(1800, 1000))

# Add the original mesh to the first subplot
plotter.subplot(0, 0)
plotter.add_mesh(pv_mesh, color="lightblue")
plotter.add_title("Original Mesh", font_size=10)

# Add the simplified mesh to the second subplot
plotter.subplot(0, 1)
plotter.add_mesh(pv_mesh_simplified, color="lightgreen")
plotter.add_title("Simplified Mesh", font_size=10)

# Add the oversampled mesh to the third subplot
plotter.subplot(1, 0)
plotter.add_mesh(pv_mesh_oversampled, color="lightblue")
plotter.add_title("Oversampled Mesh", font_size=10)

# Display the plotter
plotter.show()
"""

# ====== Normal Vector Visualization ====== #
"""
normals = pv_mesh.point_normals

plotter = pv.Plotter()
plotter.add_mesh(pv_mesh, copy_mesh=True, color='lightgray')
plotter.add_arrows(pv_mesh.points, normals, mag=0.05, color='lightblue')
plotter.show()
"""

# ====== Mesh Curvature Computation ====== #

# Call pyvista mesh curvature computation
k1 = pv_mesh.curvature(curv_type='maximum')
k2 = pv_mesh.curvature(curv_type='minimum')

curv = np.maximum(k1, k2)

pv_mesh["curv_map"] = curv

cmin = np.percentile(curv, 8)
cmax = np.percentile(curv, 95)

# Plot the curvature
plotter = pv.Plotter()
plotter.add_mesh(pv_mesh, copy_mesh=True, scalars='curv_map', clim=[cmin, cmax], cmap='jet')
plotter.show()