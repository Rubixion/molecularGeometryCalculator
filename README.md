# Molecular Geometry Calculator

Started as a C++ console app that parsed chemical formulas, looked up VSEPR geometry, and printed bond angles to stdout. It worked fine but wasn't very useful or shareable.

Rebuilt as a web viewer so it could be embedded in the Ollie.ml website. The core logic is the same, but now it renders the actual 3D molecular structure using Three.js (WebGPU) and pulls real data from the PubChem API. Ionic compounds like Na₂SO₄ that don't have PubChem entries fall back to a synthetic structure built from the formula unit.

## What it does

- Search by name (*caffeine*, *aspirin*) or formula (*H₂O*, *Na₂SO₄*)
- 3D structure from PubChem's conformer database, 2D layout fallback if no conformer exists
- VSEPR geometry detection and bond angle for single-centre molecules
- Click any atom for element data, bonding info, formal charge, hybridisation

## Controls

| | |
|---|---|
| Drag | Orbit |
| Scroll | Zoom |
| Right-drag | Pan |
| R | Reset view |
| Click atom | Atom info |

## Stack

Three.js r169 (WebGPU renderer, TSL materials) · PubChem REST API · single HTML file, no build step

## Legacy

The original C++ project is in `legacy/`. It uses a hardcoded element database and VSEPR lookup table. No rendering — just terminal output.

## New Repo

This project is now integrated into the ollie frontend repo:
https://github.com/Rubixion/ollie-frontend
