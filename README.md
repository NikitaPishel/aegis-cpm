# Aegis CPM 
> [Introduction](#introduction)

> [Installation](#installation)

> [User Manual](#user-manual)

> [Contribution](#contribution)

---

## Introduction 
This project helps to calculate stress in bridges 

### Features 
- JSON inputting 
- Based on von Mises stress equation 
- Uses custom graphic interface 
- Minimalistic 

### Upcoming 
- Accounting for non-structural parts of the bridge in calculations 
- Switching bridge diagrams without recompilation

---

## Installation
### For ubuntu/debian:
1.  **Install Git (if necessary):**
    ```bash
    sudo apt update
    sudo apt install git
    ```

2.  **Clone the Repository:**
    ```bash
    git clone https://github.com/NikitaPishel/aegis-cpm
    cd aegis-cpm
    ```

3.  **Run the Installation Script:**
    ```bash
    chmod +x ./devBuild.sh
    ./devBuild.sh -DAEGIS_BUILD_TESTS=OFF
    ```

4. **Done! Now you can launch it like this:**
    ```bash
    nsketch
    ```


---

## User Manual
Structure is fully described in a json file. When you open this file you will see this: 
```json
{
    "safetyFactor": 2.0,

    "joints": [
        {
            "xPos": 0.0,
            "yPos": 0.0
        },
        <...>
    ],

    "beams": [
        {
            "originIndex": 0,

            "length": 50,
            "width": 1,
            "height": 1,

            "material": "base.wood.oak"
        },
        <...>
    ]
}
```

Let's go step by step through the process of creating your own structure 

### Safety Factor 
You can set up your safety factor like this:
```json
"safetyFactor": x
```

Where `x` is your SF

### Joints 
#### Joints list
All joints should be added to this list:
```json
"joints": {
    <Joints Here!>
}
```

#### Addding a joint to the list
To add a joint you will use:
```json
{
"xPos": 0.0,
"yPos": 0.0
},
```

Where `"xPos"` is a x position of a joint and `"yPos"` is a y position of a joint.

### Beams 
#### Beams list
All joints should be added to this list:
```json
"beams": {
    <Beams Here!>
}
```

#### Adding a beam to the list
To add a beam to the structure you will use:
```json
 {
"originIndex": 0,

"length": 50,
"width": 1,
"height": 1,

"material": "base.wood.oak"
},
```

- `"originIndex"` - represents the index of a joint that this beam is connected to. **Numeration of joints starts from 0** 
- `"length"` - is a horizontal dimension of a beam 
- `"width"` - is a horizontal length of a cross-section across a beam 
- `"height"` - is a vertical dimension of a cross-section across a beam 
- `"material"` - represents a material a beam is made of

#### **List of all materials**
| Material | Name |
| --- | --- |
| Steel S235 | "base.steel.S235" |
| Steel S355 | "base.steel.S355" |
| Alluminum 6061 | "base.alluminum.6061" |
| Alluminum 2014 | "base.alluminum.2014" |
| American White Oak | "base.wood.oak" |

---

## Contribution
**This is a showcase project.** Any contribution won't be accepted or done to this project consistently. Even though, I suggest you create forks of this app or use any parts of its code for your own needs.