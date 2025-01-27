class ParkingSystem:
    def __init__(self, big: int, medium: int, small: int):
        self.spaces = [big, medium, small]
        
    def addCar(self, carType: int) -> bool:
        if self.spaces[carType-1] <= 0:
            return False
        
        self.spaces[carType-1] -= 1
        return True

# Can use array instead of dict to make type to available spaces since we have a defined boundary of 1-3, similar to how we can count using arrays for letters     


# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)