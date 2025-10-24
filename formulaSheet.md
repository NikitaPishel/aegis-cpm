
# Beam Stress Calculation Reference

This document summarizes the key formulas used for calculating shear, bending, and combined stresses in a fixed–fixed rectangular beam under uniform self-weight. Each section includes the formula, its purpose, and important usage notes.

---
## Navigation
> [Cross Section Geometry](#1-cross-section-geometry)

> [Load and Force definitions](#2-load-and-force-definitions)

> [Internal shear and bending moment](#3-internal-shear-and-bending-effects-fixedfixed-beam)

> [Stress distribution](#4-stress-distribution-along-cross-section)

> [Stress evaluation](#5-combined-and-maximum-stress-evaluation)

> [Combined Distributed force](#6-superposition-if-multiple-loads-exist)

> [Formula table](#7-formula-summary-table)
---

## 1. Cross-Section Geometry

### **Cross-Sectional Area**
$$
A = bh
$$

**Notes:**  
- $b$ = width  
- $h$ = height  

### **Second Moment of Area (Rectangle about Neutral Axis)**
$$
I = \dfrac{b h^3}{12}
$$

---

## 2. Load and Force Definitions

### **Weight of a beam**
$$
F = \rho A L g
$$

**Notes:**  
- Represents resultant of uniformly distributed load from beam self-weight.
- Produces uniform force along the beam

### **Platform weight distribution across multiple beams**
$$
w_i = e^{-k \left| x_i - x_{cg} \right|}
$$

$$
F_i = F \, \frac{w_i}{W}
$$

$$
\sum_i \frac{w_i}{W} = 1
$$

$$
W = \sum_i w_i
$$

**Notes:**
- Used to find force acting on a beam from a platform above
- In above formulas, $F$ is a total weight of a platform
- As $\frac{w_i}{W}$ is a factor acting on a beam $i$, weight acting on beam is $F_i$
- Assumes platform has the same length as beams supporting it
- Beams that hold the platform are considered to be perpendicular

### **Allowed Stress**
$$
\sigma_{\text{allow}} = \dfrac{\sigma_y}{SF}
$$

**Notes:**  
- Based on material yield strength $\sigma_y$ and chosen safety factor \(SF\).

---

## 3. Internal Shear and Bending Moment

### **Shear Force at Position $x$**
$$
V(x) = \dfrac{F}{2} - \dfrac{Fx}{L}
$$

**Notes:**  
- Searches for Fixed-Fixed connection loads.
- Assumes there's uniform load over the whole beam.

### **Bending Moment at Position \( x \)**
$$
M(x) = \dfrac{F x}{2} - \dfrac{F x^2}{2L} - \dfrac{FL}{12}
$$

**Notes:**  
- Includes end fixity correction: $\dfrac{FL}{12}$.

---

## 4. Stress Distribution Along Cross-Section

### **First Moment of Area at Height \( y \)**
$$
Q(y) = \dfrac{b}{2}\left[\left(\dfrac{h}{2}\right)^2 - y^2\right]
$$

**Notes:**  
- Valid for $y \le \dfrac{h}{2}$.  

### **Shear Stress at Height \( y \)**
$$
\tau(y) = \dfrac{V(x) \cdot Q(y)}{I \cdot b}
$$

**Notes:**  
- Maximum at neutral axis $(y = 0)$.

### **Bending Stress at Height \( y \)**
$$
\sigma(y) = \dfrac{M(x) \cdot y}{I}
$$

**Notes:**  
- Varies linearly from neutral axis; max at $y = \pm \dfrac{h}{2}$.

---

## 5. Combined and Maximum Stress Evaluation

### **Equivalent (von Mises) Stress**
$$
\sigma_{eq} = \sqrt{\sigma^2 + 3\tau^2}
$$

**Notes:**  
- Represents total stress at a certain point of a beam

### **Maximum Stress in Section**
$$
\sigma_{\text{max}} = \max\left[\,\sigma_{eq}(y)\,\right]
$$

**Notes:**  
- Evaluated by scanning from $y = 0$ to $y = \dfrac{h}{2}$.

### **Stress Utilization Ratio**
$$
U = \dfrac{\sigma_{\text{max}}}{\sigma_{\text{allow}}}
$$

**Notes:**  
- $U < 1 \Rightarrow$ safe; $U > 1 \Rightarrow$ failure risk.

---

## 6. Superposition (If Multiple Loads Exist)

### **Total Shear**
$$
V_{\text{total}}(x) = \sum V_i(x)
$$

### **Total Moment**
$$
M_{\text{total}} = \sum M_i(x)
$$

**Notes:**  
- Applies principle of superposition for multiple loads or effects.

---

## 7. Formula Summary Table

| Purpose | Formula |
|---------|---------|
| Cross-sectional area | $$A = bh$$ |
| Second moment of area | $$I = \dfrac{b h^3}{12}$$ |
| Weight of a beam | $$F = \rho A L g$$ |
| support distribured force | $$w_i = e^{-k \left\| x_i - x_{cg} \right\|}$$ |
| support force | $$F_i = F \frac{w_i}{W}$$ |
| Allowable stress | $$\sigma_{\text{allow}} = \dfrac{\sigma_y}{SF}$$ |
| Shear force | $$V(x) = \dfrac{F}{2} - \dfrac{F x}{L}$$ |
| Bending moment | $$M(x) = \dfrac{F x}{2} - \dfrac{F x^2}{2L} - \dfrac{FL}{12}$$ |
| First moment of area | $$Q(y) = \dfrac{b}{2}\left[\left(\dfrac{h}{2}\right)^2 - y^2\right]$$ |
| Shear stress | $$\tau(y) = \dfrac{V(x) \cdot Q(y)}{I \cdot b}$$ |
| Bending stress | $$\sigma(y) = \dfrac{M(x) \cdot y}{I}$$ |
| Equivalent stress | $$\sigma_{eq} = \sqrt{\sigma^2 + 3\tau^2}$$ |
| Maximum stress | $$\sigma_{\text{max}} = \max\left[\sigma_{eq}(y)\right]$$ |
| Utilization ratio | $$U = \dfrac{\sigma_{\text{max}}}{\sigma_{\text{allow}}}$$ |

---