from raytestpy import raytest
import pybullet as p
import numpy as np

np.random.seed(0)

def check(lst_raytest_dist, pybullet_dist):
    for raytest_dist in lst_raytest_dist:
        if np.abs(raytest_dist - pybullet_dist) < 0.1:
            return True
    return False

def test_raytest():
    #file_path = "stl_parser/Box1x1x1.stl"
    ray_start_list = [np.array([0, 0, 2.0]), np.array([0, 0, -2.0])]
    ray_dir_list = [np.array([0, 0, -1.0]), np.array([0, 0, 1.0])]

    normalize = lambda x: x/np.linalg.norm(x)

    for i in range(100):
        ray_start = normalize(np.random.randn(3))
        ray_dir = normalize(np.array([0, 0, 0.0]) - ray_start)

        file_path = "./tests/nontextured.stl"
        ret = raytest(file_path, ray_start, ray_dir)

        p.connect(p.DIRECT)
        model = p.loadURDF("./tests/nontextured.urdf")
        hit_pos = p.rayTest(ray_start, ray_dir)[0][3]
        dist = np.linalg.norm(np.array(hit_pos - ray_start))
        assert check(ret, dist)
