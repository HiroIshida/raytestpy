from raytestpy import raytest
import pybullet as p
import numpy as np

def check(lst_raytest_dist, pybullet_dist):
    for raytest_dist in lst_raytest_dist:
        if np.abs(raytest_dist - pybullet_dist) < 0.02:
            return True
    return False

def test_raytest():
    #file_path = "stl_parser/Box1x1x1.stl"
    ray_start_list = [np.array([0, 0, 2.0]), np.array([0, 0, -2.0])]
    ray_dir_list = [np.array([0, 0, -1.0]), np.array([0, 0, 1.0])]

    for ray_start, ray_dir in zip(ray_start_list, ray_dir_list):
        file_path = "./tests/nontextured.stl"
        ret = raytest(file_path, ray_start, ray_dir)

        p.connect(p.DIRECT)
        model = p.loadURDF("./tests/nontextured.urdf")
        hit_pos = p.rayTest(ray_start, ray_dir)[0][3]
        dist = np.linalg.norm(np.array(hit_pos - ray_start))

        check(ret, dist)
