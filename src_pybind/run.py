
import time
from src_pybind.pybindc import  UCharP,DataWrapper
def test():
    import sys
    from src_pybind.pybindc import  UCharP
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
    UCharP(100000)
def testDataWrapper():
    dataWrapper=DataWrapper()
    length=100000000
    dataWrapper.createData(length,"left")
    dataWrapper.createData(length,"right")
    dataWrapper.createData(length,"res")
    dataWrapper.setValue(3,"left")
    dataWrapper.setValue(7,"right")
    loop=100
    start_time=time.time()
    for i in range(loop):
        dataWrapper.mul_operation("left","right","res")
    end_time=time.time()
    # dataWrapper.print_value("res")
    print(f"python level mul:{length} loop:{loop} time consume:{end_time-start_time}")

if __name__=="__main__":
    testDataWrapper()
    print("run is done")