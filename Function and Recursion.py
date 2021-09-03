# function

# *args returns tuple

# def full_name(*args):
#     if len(args) == 1:
#         print(f"{args[0]}")
#     else:
#         print(f"{args[0]} {args[1]}")

# if __name__ == "__main__":
#
#     full_name("John", "Parker")
#     full_name("Tom")

# **kwargs returns dictionary

# def full_name(**kwargs):
#     try:
#         print(f"{kwargs['first_name']} {kwargs['last_name']}")
#     except KeyError:
#         print(f"{kwargs['first_name']}")

# recursion
# import sys
# def count(i):
#     print(i)
#     i += 1
#     if i < 10:
#         # sys.exit(0)
#         count(i)

# def full_name(f_name):
#     print(f"Hello {f_name}")
#
#
# if __name__ == "__main__":
#     # full_name(first_name = "Tom")
#     # full_name(first_name= "John", last_name= "Parker")
#     # count(1)
#     full_name('john')

#
# def full_name(**kwargs):
#     try:
#         print(f"{kwargs['first_name']} {kwargs['last_name']}")
#     except KeyError:
#         print(f"{kwargs['first_name']}")