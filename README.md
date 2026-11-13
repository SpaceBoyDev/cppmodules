# C++ Modules

This repository contains the exercises of the C++ piscine / module series, organized by topic. Each folder focuses on a specific concept of modern C++ and is divided into sub-exercises (`ex00`, `ex01`, etc.).

The goal is to practice object-oriented programming, memory management, operator overloading, inheritance, polymorphism, templates, and the STL in a structured way.

---

## Module 00

### cppmodules0

Introduction to C++ basics.
- Input/output streams
- Classes and instance creation
- Constructors and destructors
- Basic program structure and code organization

This module establishes the foundations of C++ programming and the standard style expected in the rest of the project.

---

## Module 01

### cppmodules01

Memory allocation and class fundamentals.
- `new` / `delete`
- References and pointers
- Zombie and horde management
- Encapsulation and object lifetime

The focus is on understanding how memory works in C++ and how to build clean, reusable classes.

---

## Module 02

### cppmodules02

Fixed-point arithmetic and operator overloading.
- Classes with canonical form
- Overloaded operators
- Comparison and arithmetic operators
- Fixed-point number implementation

This module teaches how to build robust numerical classes and how to properly implement class operators.

---

## Module 03

### cppmodules03

Inheritance and polymorphism.
- Base and derived classes
- Virtual methods
- Constructor/destructor chaining
- Specialization with ClapTrap, ScavTrap, FragTrap and DiamondTrap

The main objective is to understand how objects behave across inheritance hierarchies.

---

## Module 04

### cppmodules04

Abstract classes and subtype polymorphism.
- Virtual destructors
- Pure virtual functions
- Abstract base classes
- Animal / Cat / Dog / Brain hierarchy

This module expands the use of polymorphism and teaches the difference between interface and implementation.

---

## Module 05

### cppmodules05

Exceptions and advanced class design.
- Exception handling
- Try / catch blocks
- Form validation and bureaucracy examples
- Strict class invariants

The aim is to understand how to keep programs safe and predictable under invalid conditions.

---

## Module 06

### cppmodules06

C++ type casting and conversion rules.
- `static_cast`
- `dynamic_cast`
- `reinterpret_cast`
- `const_cast`
- Type identification and conversion safety

This module focuses on how C++ handles conversions and why explicit casts are essential.

---

## Module 07

### cppmodules07

Templates and generic programming.
- Function templates
- Class templates
- Generic containers
- Reusable code design

The goal is to learn how to write code that works with multiple types without duplicating logic.

---

## Module 08

### cppmodules08

STL and data structures.
- `std::vector`
- `std::map`
- Iterators and algorithms
- Standard library usage

This module introduces the Standard Template Library and teaches how to work with modern C++ containers efficiently.

---

## Module 09

### cppmodules09

Advanced C++ and containers.
- Generic algorithms
- STL containers and their behavior
- Complex object management
- Practical problem solving with C++ tools

This final module consolidates the concepts seen throughout the project and emphasizes clean, idiomatic C++.

---

## How to use

Each exercise contains its own `Makefile` and can be compiled independently, for example:

```bash
cd cppmodules03/ex02
make
./app
```

The exact binary name may vary by exercise, but the pattern is the same in each project directory.

---

## Summary

This series follows the classic 42 progression:

- Practice the syntax and structure of C++
- Learn object-oriented and generic programming
- Master memory model and class design
- Use the STL correctly and idiomatically

It is a solid path to become comfortable with modern C++ from the fundamentals to advanced concepts.
