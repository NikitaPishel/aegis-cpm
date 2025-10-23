
# Beam Stress Calculation Reference

This document summarizes the key formulas used for calculating shear, bending, and combined stresses in a fixed–fixed rectangular beam under uniform self-weight. Each section includes the formula, its purpose, and important usage notes.

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

### **Total Force from Self-Weight**
$$
F = \rho A L
$$

**Notes:**  
- Represents resultant of uniformly distributed load from beam self-weight.

### **Allowable Stress**
$$
\sigma_{\text{allow}} = \dfrac{\sigma_y}{SF}
$$

**Notes:**  
- Based on material yield strength $\sigma_y$ and chosen safety factor \(SF\).

---

## 3. Internal Shear and Bending Effects (Fixed–Fixed Beam)

### **Shear Force at Position $x$**
$$
V(x) = \dfrac{F}{2} - \dfrac{Fx}{L}
$$

**Notes:**  
- Assumes uniform load and symmetric support reactions.

### **Bending Moment at Position \( x \)**
$$
M(x) = \dfrac{F x}{2} - \dfrac{F x^2}{2L} - \dfrac{FL}{12}
$$

**Notes:**  
- Includes end fixity correction: $\dfrac{FL}{12}$.

---

## 4. Stress Distribution Along Cross-Section (at Given $x$)

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
- Used for ductile material failure analysis.

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
