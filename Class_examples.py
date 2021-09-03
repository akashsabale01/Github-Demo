# class Person:
#
#     def __init__(self, f_name, l_name, age, gender):
#         self.f_name = f_name
#         self.l_name = l_name
#         self.age = age
#         self.gender = gender
#         print("Constructor called when object is created")
#
#     def get_fullname(self):
#         return f"your fullname is {self.f_name} {self.l_name}"
#
#     # when object is printed then it calls str method of class
#     def __str__(self):
#         print("in str method")
#         return f"{self.age} {self.gender}"
#
#
# p = Person("Akash", "Sable", 20, "M")
# print(p.get_fullname())
# print(p)
#
# # changing value
# p.f_name = "John"
# print(p.get_fullname())
#
# # deleting value(i.e deleting attribute)
# del p.age
# p.age = 19
# print(p.age) # gives AttributeError: 'Person' object has no attribute 'gender'
