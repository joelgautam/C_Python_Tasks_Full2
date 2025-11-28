import array_module as arr

arr.init(5)
arr.set(0, 10)
arr.set(1, 20)

print(arr.get(0))
print(arr.get(1))

arr.free()
