# CoopShooter

### Creating the Weapon
- Create a Weapon Class in `C++`
- Create BluePrint from the Weapon Class, named rifle
- Add a placeholder mesh to the BP_Rifle
    - Player Pawn BeginPlay Event:
        - SpawnActor, Select the Rifle
        - AttachActorToComponent
            - Select the PlayerPawn Mesh
            - Selected the Skeleton, and added a socket to the right hand.

### Notes

Compile errors when using the UPhysicalMaterial
```c++
// Note: this UPhysicalMaterial required me to add the module PhysicsCore to CoopShooter.uproject file.
EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
UParticleSystem* SelectedEffect = DefaultImpactEffect;
```
