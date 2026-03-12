# SomeGame

A third-person game prototype developed in Unreal Engine showcasing modular gameplay programming. This project utilizes a hybrid C++ and Blueprint approach to build scalable, component-driven systems for player interaction, combat mechanics, and puzzle-solving.

## Core Systems & Technical Highlights:

Component-Based Interaction: Developed a robust interaction system using Unreal Interfaces (BPI_Interactable) and Actor Components (BPC_PlayerInteraction) to handle dynamic interactions with environmental puzzles (Doors, Buttons, Keys).

Universal Damage Framework: Engineered a scalable damage system (BPC_DamageSystem, BPI_damagable) using custom structs and enums to manage damage types, hit responses, and health UI updates across different entity types (Player, Enemies).

Hybrid C++ Architecture: Programmed core interactable actors (BP_Door.cpp, BP_button.cpp) and the base player class in native C++ for performance, selectively exposing properties to Blueprints for rapid designer iteration.

Modern Input Handling: Fully integrated Unreal's Enhanced Input System for modular control mapping (movement, combat, interaction).


###  - Own gameplay ability system (GAS)
###  - Interaction system
###  - Button door (c++)
###  - Puzzle systems (c++)
###  - Enemy AI
