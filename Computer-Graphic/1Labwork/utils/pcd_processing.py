import open3d as o3d

def read_pcd(FILE_NAME):
    # Try open and read the FILE_NAME
    try:
        pcd = o3d.io.read_point_cloud(FILE_NAME, format="xyzn")
        return pcd
    except:
        print("Couldn't read file")

def convert_pcd_to_mesh(pcd):
    try:
        mesh, densities = o3d.geometry.TriangleMesh.create_from_point_cloud_poisson(
            pcd, depth=7
        )  # depth=9
        return mesh
    except:
        print("Invalid Data...")
