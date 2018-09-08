# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`main`](#main_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)`            | 
`class `[`CIExyz`](#class_c_i_exyz) | this class uses the base class [Color](#class_color) and implements a CIE xyz color space in D65 white point [CIExyz](#class_c_i_exyz) stores a color in CIE xyz whit a d65 white point representation
`class `[`Color`](#class_color) | this class is the main base for color representation in this program
`class `[`ColorFactory`](#class_color_factory) | this class stores all Factories, [ColorFactory](#class_color_factory) initializes a New [Color](#class_color) object when required, returns what kind of operation can be done with a specific color representation and returns the result using the permitted operations
`class `[`ColorModel`](#class_color_model) | [ColorModel](#class_color_model) implements the class [Model](#class_model) in the context of color representation.
`class `[`ConsoleView`](#class_console_view) | [ConsoleView](#class_console_view) exestends the [View](#class_view) class Console provides an interface in terminal line.
`class `[`Controller`](#class_controller) | this class handles the connection between model and view
`class `[`CYMK`](#class_c_y_m_k) | this class uses as base the class [CIExyz](#class_c_i_exyz)[CYMK](#class_c_y_m_k) stores a color in [CYMK](#class_c_y_m_k) representation
`class `[`Factory`](#class_factory) | 
`class `[`Factory< T >`](#class_factory_3_01_t_01_4) | this class extends [GenericFactory](#class_generic_factory) and implements getNewColor() and getNewColor(const Color* color) inizializes the map allColorFactories in [ColorFactory](#class_color_factory) and makes available to [ColorFactory](#class_color_factory) a constructor for the new color requested
`class `[`GenericFactory`](#class_generic_factory) | 
`class `[`HistoryWindow`](#class_history_window) | 
`class `[`HSL`](#class_h_s_l) | this class uses as base the class [CIExyz](#class_c_i_exyz)[HSL](#class_h_s_l) stores a color in [HSL](#class_h_s_l) representation
`class `[`IllegalColorException`](#class_illegal_color_exception) | 
`class `[`MainWindow`](#class_main_window) | 
`class `[`MainWindows`](#class_main_windows) | this class uses as base the class [View](#class_view)[MainWindows](#class_main_windows) uses the qt libraries for the GUI
`class `[`Model`](#class_model) | this abstract class is used by controller to be connected to the view
`class `[`RGB`](#class_r_g_b) | this class uses the as base class [CIExyz](#class_c_i_exyz)[RGB](#class_r_g_b) stores a color in [RGB](#class_r_g_b) representation
`class `[`View`](#class_view) | 
`class `[`YUV`](#class_y_u_v) | this class uses as base the class [RGB](#class_r_g_b)[YUV](#class_y_u_v) stores a color in [YUV](#class_y_u_v) representation

## Members

#### `public int `[`main`](#main_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)` {#main_8cpp_1a0ddf1224851353fc92bfbff6f499fa97}

# class `CIExyz` {#class_c_i_exyz}

```
class CIExyz
  : public Color
```  

this class uses the base class [Color](#class_color) and implements a CIE xyz color space in D65 white point [CIExyz](#class_c_i_exyz) stores a color in CIE xyz whit a d65 white point representation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CIExyz`](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90)`(double t_x,double t_y,double t_z)` | [CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) Constructor for CIE xyz color representation from double precision numbers.
`public  `[`CIExyz`](#class_c_i_exyz_1aa16b12dfc4f0ceac557778e5bede454c)`(const `[`CIExyz`](#class_c_i_exyz)` & c)` | [CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) copy constructor.
`public  `[`CIExyz`](#class_c_i_exyz_1a861692ec98ae70d205cbee47fc63a879)`(const `[`Color`](#class_color)` * c)` | [CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) constructor for CIE xyz color representation from [Color](#class_color) pointer in the same color space.
`public  `[`~CIExyz`](#class_c_i_exyz_1a13c440b1fa97445914886573eeed5428)`() = default` | 
`public virtual int `[`getNumberOfComponets`](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e)`() const` | [CIExyz::getNumberOfComponets](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e).
`public virtual QVector< QString > `[`getLimits`](#class_c_i_exyz_1a4c3aa6777f7720ae26b53174322a83f8)`() const` | [CIExyz::getLimits](#class_c_i_exyz_1a4c3aa6777f7720ae26b53174322a83f8).
`public virtual void `[`setComponents`](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84)`(QVector< double > componets)` | [CIExyz::setComponents](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84) set the components inside the object.
`public virtual QString `[`getRepresentation`](#class_c_i_exyz_1a19120c15d1304696909d76fae6065ebd)`() const` | CIExyz::getrepresentation.
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94)`() const` | [CIExyz::negate](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8)`(const `[`Color`](#class_color)` * c) const` | [CIExyz::mix](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8).
`public virtual `[`Color`](#class_color)` * `[`getCIE`](#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b)`() const` | [CIExyz::getCIE](#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b).
`public virtual `[`Color`](#class_color)` * `[`operator/`](#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa)`(const int & div) const` | [CIExyz::operator /](#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa).
`public virtual QVector< QString > `[`availableOperations`](#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1)`() const` | [CIExyz::availableOperations](#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1).
`public virtual QVector< double > `[`getComponents`](#class_c_i_exyz_1af8992e3ac1741c35fcb18aa2cdb554a0)`() const` | CIExyz::getComponent.

## Members

#### `public  `[`CIExyz`](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90)`(double t_x,double t_y,double t_z)` {#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90}

[CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) Constructor for CIE xyz color representation from double precision numbers.

#### Parameters
* `t_x` 

* `t_y` 

* `t_z` 

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)`

#### `public  `[`CIExyz`](#class_c_i_exyz_1aa16b12dfc4f0ceac557778e5bede454c)`(const `[`CIExyz`](#class_c_i_exyz)` & c)` {#class_c_i_exyz_1aa16b12dfc4f0ceac557778e5bede454c}

[CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) copy constructor.

#### Parameters
* `c`

#### `public  `[`CIExyz`](#class_c_i_exyz_1a861692ec98ae70d205cbee47fc63a879)`(const `[`Color`](#class_color)` * c)` {#class_c_i_exyz_1a861692ec98ae70d205cbee47fc63a879}

[CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) constructor for CIE xyz color representation from [Color](#class_color) pointer in the same color space.

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Parameters
* `c`

#### `public  `[`~CIExyz`](#class_c_i_exyz_1a13c440b1fa97445914886573eeed5428)`() = default` {#class_c_i_exyz_1a13c440b1fa97445914886573eeed5428}

#### `public virtual int `[`getNumberOfComponets`](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e)`() const` {#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e}

[CIExyz::getNumberOfComponets](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e).

#### Returns
number of componets

#### `public virtual QVector< QString > `[`getLimits`](#class_c_i_exyz_1a4c3aa6777f7720ae26b53174322a83f8)`() const` {#class_c_i_exyz_1a4c3aa6777f7720ae26b53174322a83f8}

[CIExyz::getLimits](#class_c_i_exyz_1a4c3aa6777f7720ae26b53174322a83f8).

#### Returns
limits as QVector<QString>

#### `public virtual void `[`setComponents`](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84)`(QVector< double > componets)` {#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84}

[CIExyz::setComponents](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84) set the components inside the object.

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Parameters
* `componets` with 3 values xyz

#### `public virtual QString `[`getRepresentation`](#class_c_i_exyz_1a19120c15d1304696909d76fae6065ebd)`() const` {#class_c_i_exyz_1a19120c15d1304696909d76fae6065ebd}

CIExyz::getrepresentation.

#### Returns
QString that contains name of the object

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94)`() const` {#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94}

[CIExyz::negate](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94).

#### Returns
[Color](#class_color) pointer with a new color with the negated values

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8)`(const `[`Color`](#class_color)` * c) const` {#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8}

[CIExyz::mix](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8).

#### Parameters
* `c` 

#### Returns
[Color](#class_color) pointer with a new color mixed

#### `public virtual `[`Color`](#class_color)` * `[`getCIE`](#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b)`() const` {#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b}

[CIExyz::getCIE](#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b).

#### Returns
[Color](#class_color) pointer with a clone of *this

#### `public virtual `[`Color`](#class_color)` * `[`operator/`](#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa)`(const int & div) const` {#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa}

[CIExyz::operator /](#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa).

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)`

#### `public virtual QVector< QString > `[`availableOperations`](#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1)`() const` {#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1}

[CIExyz::availableOperations](#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1).

#### Returns
all the operation that has been implemented

#### `public virtual QVector< double > `[`getComponents`](#class_c_i_exyz_1af8992e3ac1741c35fcb18aa2cdb554a0)`() const` {#class_c_i_exyz_1af8992e3ac1741c35fcb18aa2cdb554a0}

CIExyz::getComponent.

#### Returns
QVector<double> with the x y z component of the color in CIE XYZ

# class `Color` {#class_color}

this class is the main base for color representation in this program

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Color`](#class_color_1a6fae8aa8b75d27cb134234e75b41caf2)`() = default` | 
`public virtual  `[`~Color`](#class_color_1a2c0b567ad3430b6fe40f8b06c12654eb)`() = default` | 
`public int `[`getNumberOfComponets`](#class_color_1a0e16ae80374851824e791a941c6315e1)`() const` | 
`public void `[`setComponents`](#class_color_1a84ee279d59516539f2940a424018c376)`(QVector< double > componets)` | 
`public `[`Color`](#class_color)` * `[`getCIE`](#class_color_1a5d360ee273c34bceb8dd5837489a0a18)`() const` | 
`public `[`Color`](#class_color)` * `[`negate`](#class_color_1aa73035295e3e42593b11904c398f1657)`() const` | 
`public `[`Color`](#class_color)` * `[`mix`](#class_color_1ab240ddb0e1d4779703f6b2ee35a8a0e9)`(const `[`Color`](#class_color)` * c1) const` | 
`public `[`Color`](#class_color)` * `[`operator/`](#class_color_1acb25591213c391f682c9261c85dc111c)`(const int & div) const` | 
`public QVector< QString > `[`getLimits`](#class_color_1a4880c6f39c155008b711c056b21ff31b)`() const` | 
`public QVector< QString > `[`availableOperations`](#class_color_1af521a40fabd5e4718ada6531fc20ec58)`() const` | 
`public QVector< double > `[`getComponents`](#class_color_1a0c30989b24589c8725abe286cc5e7a23)`() const` | 
`public QString `[`getRepresentation`](#class_color_1a45ec07f1486ab8259cdd8630c804b9f6)`() const` | 

## Members

#### `public  `[`Color`](#class_color_1a6fae8aa8b75d27cb134234e75b41caf2)`() = default` {#class_color_1a6fae8aa8b75d27cb134234e75b41caf2}

#### `public virtual  `[`~Color`](#class_color_1a2c0b567ad3430b6fe40f8b06c12654eb)`() = default` {#class_color_1a2c0b567ad3430b6fe40f8b06c12654eb}

#### `public int `[`getNumberOfComponets`](#class_color_1a0e16ae80374851824e791a941c6315e1)`() const` {#class_color_1a0e16ae80374851824e791a941c6315e1}

#### `public void `[`setComponents`](#class_color_1a84ee279d59516539f2940a424018c376)`(QVector< double > componets)` {#class_color_1a84ee279d59516539f2940a424018c376}

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_color_1a5d360ee273c34bceb8dd5837489a0a18)`() const` {#class_color_1a5d360ee273c34bceb8dd5837489a0a18}

#### `public `[`Color`](#class_color)` * `[`negate`](#class_color_1aa73035295e3e42593b11904c398f1657)`() const` {#class_color_1aa73035295e3e42593b11904c398f1657}

#### `public `[`Color`](#class_color)` * `[`mix`](#class_color_1ab240ddb0e1d4779703f6b2ee35a8a0e9)`(const `[`Color`](#class_color)` * c1) const` {#class_color_1ab240ddb0e1d4779703f6b2ee35a8a0e9}

#### `public `[`Color`](#class_color)` * `[`operator/`](#class_color_1acb25591213c391f682c9261c85dc111c)`(const int & div) const` {#class_color_1acb25591213c391f682c9261c85dc111c}

#### `public QVector< QString > `[`getLimits`](#class_color_1a4880c6f39c155008b711c056b21ff31b)`() const` {#class_color_1a4880c6f39c155008b711c056b21ff31b}

#### `public QVector< QString > `[`availableOperations`](#class_color_1af521a40fabd5e4718ada6531fc20ec58)`() const` {#class_color_1af521a40fabd5e4718ada6531fc20ec58}

#### `public QVector< double > `[`getComponents`](#class_color_1a0c30989b24589c8725abe286cc5e7a23)`() const` {#class_color_1a0c30989b24589c8725abe286cc5e7a23}

#### `public QString `[`getRepresentation`](#class_color_1a45ec07f1486ab8259cdd8630c804b9f6)`() const` {#class_color_1a45ec07f1486ab8259cdd8630c804b9f6}

# class `ColorFactory` {#class_color_factory}

this class stores all Factories, [ColorFactory](#class_color_factory) initializes a New [Color](#class_color) object when required, returns what kind of operation can be done with a specific color representation and returns the result using the permitted operations

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `ColorModel` {#class_color_model}

```
class ColorModel
  : public Model
```  

[ColorModel](#class_color_model) implements the class [Model](#class_model) in the context of color representation.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ColorModel`](#class_color_model_1a2c2ee4adfbff8d5d5c9f7dc6fb7e9f3f)`()` | Model::Model inizialize the [ColorModel](#class_color_model) and assign the older [ColorModel](#class_color_model) if exists.
`public  `[`~ColorModel`](#class_color_model_1ace1f2efdd5fd223daa7e9cf002556a04)`()` | [ColorModel::~ColorModel](#class_color_model_1ace1f2efdd5fd223daa7e9cf002556a04) deletes all [Color](#class_color) that [ColorModel](#class_color_model) points to.
`public virtual QVector< QString > `[`availableOperations`](#class_color_model_1aab6a725338946ecec218220f5606be45)`() const` | [ColorModel::availableOperations](#class_color_model_1aab6a725338946ecec218220f5606be45).
`public virtual QVector< QString > `[`allAvailableTypes`](#class_color_model_1ac1788de4bf589070a2e915ff43d073ad)`() const` | [ColorModel::allAvailableTypes](#class_color_model_1ac1788de4bf589070a2e915ff43d073ad).
`{slot} public void `[`setLeftType`](#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37)`(QString type)` | [ColorModel::setLeftType](#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37).
`{slot} public void `[`setLeftValues`](#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5)`(QVector< QString > values)` | [ColorModel::setLeftValues](#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5).
`{slot} public void `[`setRightType`](#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38)`(QString type)` | [ColorModel::setRightType](#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38).
`{slot} public void `[`setRightValues`](#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6)`(QVector< QString > values)` | [ColorModel::setRightValues](#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6).
`{slot} public void `[`setResultType`](#class_color_model_1ae0c25592f1e201251a6090496548e762)`(QString type)` | [ColorModel::setResultType](#class_color_model_1ae0c25592f1e201251a6090496548e762) set the result type.
`{slot} public void `[`setOp`](#class_color_model_1ad51072410fbe8572066b3a53ca85a289)`(QString eOperation)` | [ColorModel::setOp](#class_color_model_1ad51072410fbe8572066b3a53ca85a289).
`{slot} public void `[`execute`](#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640)`()` | [ColorModel::execute](#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640) execute the operation.
`{slot} public void `[`getResult`](#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d)`()` | [ColorModel::getResult](#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d) set up result object.
`{slot} public void `[`getHistory`](#class_color_model_1a90bcf6ca5b8d00a14a8153970594de97)`()` | [ColorModel::getHistory](#class_color_model_1a90bcf6ca5b8d00a14a8153970594de97).
`{slot} public void `[`reset`](#class_color_model_1af5f09a79d9964daefb3ceac9c45f0034)`()` | [ColorModel::reset](#class_color_model_1af5f09a79d9964daefb3ceac9c45f0034) resets the [ColorModel](#class_color_model) instance objects.

## Members

#### `public  `[`ColorModel`](#class_color_model_1a2c2ee4adfbff8d5d5c9f7dc6fb7e9f3f)`()` {#class_color_model_1a2c2ee4adfbff8d5d5c9f7dc6fb7e9f3f}

Model::Model inizialize the [ColorModel](#class_color_model) and assign the older [ColorModel](#class_color_model) if exists.

#### Parameters
* `previous`

#### `public  `[`~ColorModel`](#class_color_model_1ace1f2efdd5fd223daa7e9cf002556a04)`()` {#class_color_model_1ace1f2efdd5fd223daa7e9cf002556a04}

[ColorModel::~ColorModel](#class_color_model_1ace1f2efdd5fd223daa7e9cf002556a04) deletes all [Color](#class_color) that [ColorModel](#class_color_model) points to.

#### `public virtual QVector< QString > `[`availableOperations`](#class_color_model_1aab6a725338946ecec218220f5606be45)`() const` {#class_color_model_1aab6a725338946ecec218220f5606be45}

[ColorModel::availableOperations](#class_color_model_1aab6a725338946ecec218220f5606be45).

#### Returns
QVector<QString> that contains all the operation that are available

#### `public virtual QVector< QString > `[`allAvailableTypes`](#class_color_model_1ac1788de4bf589070a2e915ff43d073ad)`() const` {#class_color_model_1ac1788de4bf589070a2e915ff43d073ad}

[ColorModel::allAvailableTypes](#class_color_model_1ac1788de4bf589070a2e915ff43d073ad).

#### Returns
QVector<QString> that contains all permitted types

#### `{slot} public void `[`setLeftType`](#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37)`(QString type)` {#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37}

[ColorModel::setLeftType](#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37).

#### Parameters
* `type` setup the left operand type

#### `{slot} public void `[`setLeftValues`](#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5)`(QVector< QString > values)` {#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5}

[ColorModel::setLeftValues](#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5).

#### Parameters
* `values` set values to the left operand

#### `{slot} public void `[`setRightType`](#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38)`(QString type)` {#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38}

[ColorModel::setRightType](#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38).

#### Parameters
* `type` set the right operand type

#### `{slot} public void `[`setRightValues`](#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6)`(QVector< QString > values)` {#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6}

[ColorModel::setRightValues](#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6).

#### Parameters
* `values` set values to the right operand

#### `{slot} public void `[`setResultType`](#class_color_model_1ae0c25592f1e201251a6090496548e762)`(QString type)` {#class_color_model_1ae0c25592f1e201251a6090496548e762}

[ColorModel::setResultType](#class_color_model_1ae0c25592f1e201251a6090496548e762) set the result type.

#### Parameters
* `type`

#### `{slot} public void `[`setOp`](#class_color_model_1ad51072410fbe8572066b3a53ca85a289)`(QString eOperation)` {#class_color_model_1ad51072410fbe8572066b3a53ca85a289}

[ColorModel::setOp](#class_color_model_1ad51072410fbe8572066b3a53ca85a289).

#### Parameters
* `eOperation` set up the operation that will be executed

#### `{slot} public void `[`execute`](#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640)`()` {#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640}

[ColorModel::execute](#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640) execute the operation.

#### `{slot} public void `[`getResult`](#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d)`()` {#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d}

[ColorModel::getResult](#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d) set up result object.

#### `{slot} public void `[`getHistory`](#class_color_model_1a90bcf6ca5b8d00a14a8153970594de97)`()` {#class_color_model_1a90bcf6ca5b8d00a14a8153970594de97}

[ColorModel::getHistory](#class_color_model_1a90bcf6ca5b8d00a14a8153970594de97).

#### Returns
QVector<QString> with the history of the operation that has been done

#### `{slot} public void `[`reset`](#class_color_model_1af5f09a79d9964daefb3ceac9c45f0034)`()` {#class_color_model_1af5f09a79d9964daefb3ceac9c45f0034}

[ColorModel::reset](#class_color_model_1af5f09a79d9964daefb3ceac9c45f0034) resets the [ColorModel](#class_color_model) instance objects.

# class `ConsoleView` {#class_console_view}

```
class ConsoleView
  : public View
```  

[ConsoleView](#class_console_view) exestends the [View](#class_view) class Console provides an interface in terminal line.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`ConsoleView`](#class_console_view_1ae8a2079a84bc7b7e2b8a68f927cae911)`(`[`View`](#class_view)` * parent)` | 
`public  `[`ConsoleView`](#class_console_view_1a42ca0ca912c42d743a64f7e3a80b6f26)`(const `[`ConsoleView`](#class_console_view)` & console)` | ConsoleView::ConsoleView.
`public  `[`~ConsoleView`](#class_console_view_1ac1176e89fc21883badc833e6167726d6)`() = default` | 
`{slot} public void `[`setAvailableOperations`](#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec)`(const QVector< QString > operations)` | [ConsoleView::setAvailableOperations](#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec).
`{slot} public void `[`setPermittedOperations`](#class_console_view_1a17864810f831eb58d8be275a2eaa461d)`(const QVector< QString > operations)` | [ConsoleView::setPermittedOperations](#class_console_view_1a17864810f831eb58d8be275a2eaa461d).
`{slot} public void `[`setLeftTypes`](#class_console_view_1a7dcc84dc917fb81babae471315e9cefd)`(const QVector< QString > types)` | [ConsoleView::setLeftTypes](#class_console_view_1a7dcc84dc917fb81babae471315e9cefd).
`{slot} public void `[`setLeftFields`](#class_console_view_1ae813b6a54bc56f1a22b60ee005da813e)`(const int & fields,const QVector< QString > & limits)` | [ConsoleView::setLeftFields](#class_console_view_1ae813b6a54bc56f1a22b60ee005da813e).
`{slot} public void `[`setRightTypes`](#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4)`(const QVector< QString > types)` | [ConsoleView::setRightTypes](#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4).
`{slot} public void `[`setRightFields`](#class_console_view_1a2b9ba00770ebdeda35f2b506c752248e)`(const int & fields,const QVector< QString > & limits)` | [ConsoleView::setRightFields](#class_console_view_1a2b9ba00770ebdeda35f2b506c752248e).
`{slot} public void `[`setResult`](#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37)`(const QVector< QString > result)` | [ConsoleView::setResult](#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37).
`{slot} public void `[`setResultFields`](#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3)`(const int & fields)` | [ConsoleView::setResultFields](#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3).
`{slot} public void `[`setHistory`](#class_console_view_1acd2e5ae5d77096c4227c2c9c5881926b)`(const QVector< QVector< QString >> & history)` | [ConsoleView::setHistory](#class_console_view_1acd2e5ae5d77096c4227c2c9c5881926b).
`{slot} public void `[`error`](#class_console_view_1a3c5b8df5fd316a1190f7beaa0460b29a)`(const QString & error_message)` | [ConsoleView::error](#class_console_view_1a3c5b8df5fd316a1190f7beaa0460b29a) prints error message in terminal.
`{slot} public void `[`resetType`](#class_console_view_1aba1141da17dd4f424ae296142ff7a8bd)`(QString drop,QString type)` | [ConsoleView::resetType](#class_console_view_1aba1141da17dd4f424ae296142ff7a8bd).
`{slot} public void `[`show`](#class_console_view_1a64444203b69213adbe63da93d3d03cb4)`()` | [ConsoleView::show](#class_console_view_1a64444203b69213adbe63da93d3d03cb4) inizialize the view inside the terminal.

## Members

#### `public inline  `[`ConsoleView`](#class_console_view_1ae8a2079a84bc7b7e2b8a68f927cae911)`(`[`View`](#class_view)` * parent)` {#class_console_view_1ae8a2079a84bc7b7e2b8a68f927cae911}

#### `public  `[`ConsoleView`](#class_console_view_1a42ca0ca912c42d743a64f7e3a80b6f26)`(const `[`ConsoleView`](#class_console_view)` & console)` {#class_console_view_1a42ca0ca912c42d743a64f7e3a80b6f26}

ConsoleView::ConsoleView.

#### Parameters
* `console`

#### `public  `[`~ConsoleView`](#class_console_view_1ac1176e89fc21883badc833e6167726d6)`() = default` {#class_console_view_1ac1176e89fc21883badc833e6167726d6}

#### `{slot} public void `[`setAvailableOperations`](#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec)`(const QVector< QString > operations)` {#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec}

[ConsoleView::setAvailableOperations](#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec).

#### Parameters
* `opt` sets up all operations that are available not really required

#### `{slot} public void `[`setPermittedOperations`](#class_console_view_1a17864810f831eb58d8be275a2eaa461d)`(const QVector< QString > operations)` {#class_console_view_1a17864810f831eb58d8be275a2eaa461d}

[ConsoleView::setPermittedOperations](#class_console_view_1a17864810f831eb58d8be275a2eaa461d).

#### Parameters
* `opt` sets up all operations that the user can execute

#### `{slot} public void `[`setLeftTypes`](#class_console_view_1a7dcc84dc917fb81babae471315e9cefd)`(const QVector< QString > types)` {#class_console_view_1a7dcc84dc917fb81babae471315e9cefd}

[ConsoleView::setLeftTypes](#class_console_view_1a7dcc84dc917fb81babae471315e9cefd).

#### Parameters
* `types` sets up l_types variable

#### `{slot} public void `[`setLeftFields`](#class_console_view_1ae813b6a54bc56f1a22b60ee005da813e)`(const int & fields,const QVector< QString > & limits)` {#class_console_view_1ae813b6a54bc56f1a22b60ee005da813e}

[ConsoleView::setLeftFields](#class_console_view_1ae813b6a54bc56f1a22b60ee005da813e).

#### Parameters
* `fields` sets up l_size variable

#### `{slot} public void `[`setRightTypes`](#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4)`(const QVector< QString > types)` {#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4}

[ConsoleView::setRightTypes](#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4).

#### Parameters
* `types` sets up r_types variable

#### `{slot} public void `[`setRightFields`](#class_console_view_1a2b9ba00770ebdeda35f2b506c752248e)`(const int & fields,const QVector< QString > & limits)` {#class_console_view_1a2b9ba00770ebdeda35f2b506c752248e}

[ConsoleView::setRightFields](#class_console_view_1a2b9ba00770ebdeda35f2b506c752248e).

#### Parameters
* `fields` sets up r_size variable

#### `{slot} public void `[`setResult`](#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37)`(const QVector< QString > result)` {#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37}

[ConsoleView::setResult](#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37).

#### Parameters
* `result` sets up local_result variable

#### `{slot} public void `[`setResultFields`](#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3)`(const int & fields)` {#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3}

[ConsoleView::setResultFields](#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3).

#### Parameters
* `fields` does nothing because the resultFields are the same as left operand

#### `{slot} public void `[`setHistory`](#class_console_view_1acd2e5ae5d77096c4227c2c9c5881926b)`(const QVector< QVector< QString >> & history)` {#class_console_view_1acd2e5ae5d77096c4227c2c9c5881926b}

[ConsoleView::setHistory](#class_console_view_1acd2e5ae5d77096c4227c2c9c5881926b).

#### Parameters
* `history` shows history on terminal

#### `{slot} public void `[`error`](#class_console_view_1a3c5b8df5fd316a1190f7beaa0460b29a)`(const QString & error_message)` {#class_console_view_1a3c5b8df5fd316a1190f7beaa0460b29a}

[ConsoleView::error](#class_console_view_1a3c5b8df5fd316a1190f7beaa0460b29a) prints error message in terminal.

#### Parameters
* `error_message`

#### `{slot} public void `[`resetType`](#class_console_view_1aba1141da17dd4f424ae296142ff7a8bd)`(QString drop,QString type)` {#class_console_view_1aba1141da17dd4f424ae296142ff7a8bd}

[ConsoleView::resetType](#class_console_view_1aba1141da17dd4f424ae296142ff7a8bd).

#### Parameters
* `drop` 

* `type`

#### `{slot} public void `[`show`](#class_console_view_1a64444203b69213adbe63da93d3d03cb4)`()` {#class_console_view_1a64444203b69213adbe63da93d3d03cb4}

[ConsoleView::show](#class_console_view_1a64444203b69213adbe63da93d3d03cb4) inizialize the view inside the terminal.

# class `Controller` {#class_controller}

```
class Controller
  : public QObject
```  

this class handles the connection between model and view

15/08/2018

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Controller`](#class_controller_1a7984f40669752a82c87e067bec6c3751)`(`[`Model`](#class_model)` * f_model,`[`View`](#class_view)` * f_view)` | [Controller::Controller](#class_controller_1a7984f40669752a82c87e067bec6c3751).
`public  `[`~Controller`](#class_controller_1a0ab87934c4f7a266cfdb86e0f36bc1b5)`()` | [Controller::~Controller](#class_controller_1a0ab87934c4f7a266cfdb86e0f36bc1b5).
`public void `[`connect`](#class_controller_1afe28638e4396e7b8415cbe5d05964ad2)`()` | [Controller::connect](#class_controller_1afe28638e4396e7b8415cbe5d05964ad2) Connects all the slots and signal in view and model.
`public void `[`disconnect`](#class_controller_1a1b122dccfa346274aa2e6aa5e6a7eb01)`()` | [Controller::disconnect](#class_controller_1a1b122dccfa346274aa2e6aa5e6a7eb01) disconnects all the slots and signal in view and model.
`{slot} public void `[`setUp`](#class_controller_1ac5b5525e1a9fc6914657dd8d943a0928)`()` | [Controller::setUp](#class_controller_1ac5b5525e1a9fc6914657dd8d943a0928) set up the object view usign model information.

## Members

#### `public  `[`Controller`](#class_controller_1a7984f40669752a82c87e067bec6c3751)`(`[`Model`](#class_model)` * f_model,`[`View`](#class_view)` * f_view)` {#class_controller_1a7984f40669752a82c87e067bec6c3751}

[Controller::Controller](#class_controller_1a7984f40669752a82c87e067bec6c3751).

#### Parameters
* `f_model` 

* `f_view`

#### `public  `[`~Controller`](#class_controller_1a0ab87934c4f7a266cfdb86e0f36bc1b5)`()` {#class_controller_1a0ab87934c4f7a266cfdb86e0f36bc1b5}

[Controller::~Controller](#class_controller_1a0ab87934c4f7a266cfdb86e0f36bc1b5).

#### `public void `[`connect`](#class_controller_1afe28638e4396e7b8415cbe5d05964ad2)`()` {#class_controller_1afe28638e4396e7b8415cbe5d05964ad2}

[Controller::connect](#class_controller_1afe28638e4396e7b8415cbe5d05964ad2) Connects all the slots and signal in view and model.

#### `public void `[`disconnect`](#class_controller_1a1b122dccfa346274aa2e6aa5e6a7eb01)`()` {#class_controller_1a1b122dccfa346274aa2e6aa5e6a7eb01}

[Controller::disconnect](#class_controller_1a1b122dccfa346274aa2e6aa5e6a7eb01) disconnects all the slots and signal in view and model.

#### `{slot} public void `[`setUp`](#class_controller_1ac5b5525e1a9fc6914657dd8d943a0928)`()` {#class_controller_1ac5b5525e1a9fc6914657dd8d943a0928}

[Controller::setUp](#class_controller_1ac5b5525e1a9fc6914657dd8d943a0928) set up the object view usign model information.

# class `CYMK` {#class_c_y_m_k}

```
class CYMK
  : public CIExyz
```  

this class uses as base the class [CIExyz](#class_c_i_exyz)[CYMK](#class_c_y_m_k) stores a color in [CYMK](#class_c_y_m_k) representation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CYMK`](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d)`(unsigned int c,unsigned int y,unsigned int m,unsigned int k)` | [CYMK::CYMK](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d) Constructor for [CYMK](#class_c_y_m_k) color representation from unsigned int numbers.
`public  `[`CYMK`](#class_c_y_m_k_1ab524ef2e847938b2efff28886387ec51)`(const `[`Color`](#class_color)` * from)` | [CYMK::CYMK](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d) Constructor for [CYMK](#class_c_y_m_k) color representation from [Color](#class_color) pointer.
`public  `[`CYMK`](#class_c_y_m_k_1a4bccfb3b46229aa82827bd6988efaa8c)`(const `[`CYMK`](#class_c_y_m_k)` & from)` | [CYMK::CYMK](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d) copy constructor.
`public  `[`~CYMK`](#class_c_y_m_k_1ab39102ab4de2ca8bef59da162df3d6af)`() = default` | 
`public virtual QString `[`getRepresentation`](#class_c_y_m_k_1aa523f734fd52f67ca9fcb31f0b7fe579)`() const` | CYMK::getrepresentation.
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_c_y_m_k_1a397c0109e76ff6cc331b49e4b73623ef)`() const` | [CYMK::negate](#class_c_y_m_k_1a397c0109e76ff6cc331b49e4b73623ef).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_c_y_m_k_1adeb4691eafbb53e15538a3d829f59a14)`(const `[`Color`](#class_color)` * a) const` | [CYMK::mix](#class_c_y_m_k_1adeb4691eafbb53e15538a3d829f59a14).
`public `[`Color`](#class_color)` * `[`getCIE`](#class_c_y_m_k_1ad92097bbc8fa491be286a76588285d1e)`(unsigned int c,unsigned int y,unsigned int m,unsigned int k) const` | [CYMK::getCIE](#class_c_y_m_k_1ad92097bbc8fa491be286a76588285d1e).
`public virtual QVector< double > `[`getComponents`](#class_c_y_m_k_1a46e1058b0332d73710efa5d9f4644ba2)`() const` | CYMK::getComponent.
`public virtual int `[`getNumberOfComponets`](#class_c_y_m_k_1ab3f005a1cc28f715192ad4fc90ded6b8)`() const` | [CYMK::getNumberOfComponets](#class_c_y_m_k_1ab3f005a1cc28f715192ad4fc90ded6b8).
`public virtual QVector< QString > `[`getLimits`](#class_c_y_m_k_1a9e0f2df82394cab1f95782f381c560ab)`() const` | [CYMK::getLimits](#class_c_y_m_k_1a9e0f2df82394cab1f95782f381c560ab).
`public virtual void `[`setComponents`](#class_c_y_m_k_1a897a2a1030cfd10dc16d5e2de825b45e)`(QVector< double > componets)` | [CYMK::setComponents](#class_c_y_m_k_1a897a2a1030cfd10dc16d5e2de825b45e) set the components inside the object.

## Members

#### `public  `[`CYMK`](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d)`(unsigned int c,unsigned int y,unsigned int m,unsigned int k)` {#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d}

[CYMK::CYMK](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d) Constructor for [CYMK](#class_c_y_m_k) color representation from unsigned int numbers.

#### Parameters
* `c` 

* `y` 

* `m` 

* `k`

#### `public  `[`CYMK`](#class_c_y_m_k_1ab524ef2e847938b2efff28886387ec51)`(const `[`Color`](#class_color)` * from)` {#class_c_y_m_k_1ab524ef2e847938b2efff28886387ec51}

[CYMK::CYMK](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d) Constructor for [CYMK](#class_c_y_m_k) color representation from [Color](#class_color) pointer.

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Parameters
* `from`

#### `public  `[`CYMK`](#class_c_y_m_k_1a4bccfb3b46229aa82827bd6988efaa8c)`(const `[`CYMK`](#class_c_y_m_k)` & from)` {#class_c_y_m_k_1a4bccfb3b46229aa82827bd6988efaa8c}

[CYMK::CYMK](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d) copy constructor.

#### Parameters
* `from`

#### `public  `[`~CYMK`](#class_c_y_m_k_1ab39102ab4de2ca8bef59da162df3d6af)`() = default` {#class_c_y_m_k_1ab39102ab4de2ca8bef59da162df3d6af}

#### `public virtual QString `[`getRepresentation`](#class_c_y_m_k_1aa523f734fd52f67ca9fcb31f0b7fe579)`() const` {#class_c_y_m_k_1aa523f734fd52f67ca9fcb31f0b7fe579}

CYMK::getrepresentation.

#### Returns
QString that contains name of the object

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_c_y_m_k_1a397c0109e76ff6cc331b49e4b73623ef)`() const` {#class_c_y_m_k_1a397c0109e76ff6cc331b49e4b73623ef}

[CYMK::negate](#class_c_y_m_k_1a397c0109e76ff6cc331b49e4b73623ef).

#### Returns
[Color](#class_color) pointer with a new color with the negated values

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_c_y_m_k_1adeb4691eafbb53e15538a3d829f59a14)`(const `[`Color`](#class_color)` * a) const` {#class_c_y_m_k_1adeb4691eafbb53e15538a3d829f59a14}

[CYMK::mix](#class_c_y_m_k_1adeb4691eafbb53e15538a3d829f59a14).

#### Parameters
* `a` 

#### Returns
[Color](#class_color) pointer with a new color mixed as [CYMK](#class_c_y_m_k)

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_c_y_m_k_1ad92097bbc8fa491be286a76588285d1e)`(unsigned int c,unsigned int y,unsigned int m,unsigned int k) const` {#class_c_y_m_k_1ad92097bbc8fa491be286a76588285d1e}

[CYMK::getCIE](#class_c_y_m_k_1ad92097bbc8fa491be286a76588285d1e).

#### Parameters
* `c` 

* `y` 

* `m` 

* `k` 

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Returns
[Color](#class_color) pointer with a clone of *this in the [CIExyz](#class_c_i_exyz) format

#### `public virtual QVector< double > `[`getComponents`](#class_c_y_m_k_1a46e1058b0332d73710efa5d9f4644ba2)`() const` {#class_c_y_m_k_1a46e1058b0332d73710efa5d9f4644ba2}

CYMK::getComponent.

#### Returns
QVector<double> with the cyan, yellow, magenta, key black component of the color in [CYMK](#class_c_y_m_k)

#### `public virtual int `[`getNumberOfComponets`](#class_c_y_m_k_1ab3f005a1cc28f715192ad4fc90ded6b8)`() const` {#class_c_y_m_k_1ab3f005a1cc28f715192ad4fc90ded6b8}

[CYMK::getNumberOfComponets](#class_c_y_m_k_1ab3f005a1cc28f715192ad4fc90ded6b8).

#### Returns
number of componets

#### `public virtual QVector< QString > `[`getLimits`](#class_c_y_m_k_1a9e0f2df82394cab1f95782f381c560ab)`() const` {#class_c_y_m_k_1a9e0f2df82394cab1f95782f381c560ab}

[CYMK::getLimits](#class_c_y_m_k_1a9e0f2df82394cab1f95782f381c560ab).

#### Returns
limits of [CYMK](#class_c_y_m_k) as QVector<QString>

#### `public virtual void `[`setComponents`](#class_c_y_m_k_1a897a2a1030cfd10dc16d5e2de825b45e)`(QVector< double > componets)` {#class_c_y_m_k_1a897a2a1030cfd10dc16d5e2de825b45e}

[CYMK::setComponents](#class_c_y_m_k_1a897a2a1030cfd10dc16d5e2de825b45e) set the components inside the object.

#### Parameters
* `componets`

# class `Factory` {#class_factory}

```
class Factory
  : public GenericFactory
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Factory`](#class_factory_1aa9715c3cc1d43c571191d8bbc1203633)`()` | 
`public  `[`~Factory`](#class_factory_1a46094d88ba8e37cf2d56a35878294a09)`() = default` | 
`public inline virtual `[`Color`](#class_color)` * `[`getNewColor`](#class_factory_1a6c7dcfb9ba1de182fcd6b2e0990d02f3)`() const` | 
`public inline virtual `[`Color`](#class_color)` * `[`getNewColor`](#class_factory_1a4bfca7f98466684ad447c753b678628a)`(const `[`Color`](#class_color)` * color) const` | 

## Members

#### `public inline  `[`Factory`](#class_factory_1aa9715c3cc1d43c571191d8bbc1203633)`()` {#class_factory_1aa9715c3cc1d43c571191d8bbc1203633}

#### `public  `[`~Factory`](#class_factory_1a46094d88ba8e37cf2d56a35878294a09)`() = default` {#class_factory_1a46094d88ba8e37cf2d56a35878294a09}

#### `public inline virtual `[`Color`](#class_color)` * `[`getNewColor`](#class_factory_1a6c7dcfb9ba1de182fcd6b2e0990d02f3)`() const` {#class_factory_1a6c7dcfb9ba1de182fcd6b2e0990d02f3}

#### `public inline virtual `[`Color`](#class_color)` * `[`getNewColor`](#class_factory_1a4bfca7f98466684ad447c753b678628a)`(const `[`Color`](#class_color)` * color) const` {#class_factory_1a4bfca7f98466684ad447c753b678628a}

# class `Factory< T >` {#class_factory_3_01_t_01_4}

this class extends [GenericFactory](#class_generic_factory) and implements getNewColor() and getNewColor(const Color* color) inizializes the map allColorFactories in [ColorFactory](#class_color_factory) and makes available to [ColorFactory](#class_color_factory) a constructor for the new color requested

this class is uses as base object to recall a Factory<t> getNewColor

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `GenericFactory` {#class_generic_factory}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Color`](#class_color)` * `[`getNewColor`](#class_generic_factory_1a1e4a2993cb1684a24ed3edfb06efdaed)`() const` | 
`public `[`Color`](#class_color)` * `[`getNewColor`](#class_generic_factory_1a478ac68c07e43943450d76babc963bab)`(const `[`Color`](#class_color)` * color) const` | 
`public virtual  `[`~GenericFactory`](#class_generic_factory_1ac39fdfdd0347bf14d5fc031e9420952f)`() = default` | 

## Members

#### `public `[`Color`](#class_color)` * `[`getNewColor`](#class_generic_factory_1a1e4a2993cb1684a24ed3edfb06efdaed)`() const` {#class_generic_factory_1a1e4a2993cb1684a24ed3edfb06efdaed}

#### `public `[`Color`](#class_color)` * `[`getNewColor`](#class_generic_factory_1a478ac68c07e43943450d76babc963bab)`(const `[`Color`](#class_color)` * color) const` {#class_generic_factory_1a478ac68c07e43943450d76babc963bab}

#### `public virtual  `[`~GenericFactory`](#class_generic_factory_1ac39fdfdd0347bf14d5fc031e9420952f)`() = default` {#class_generic_factory_1ac39fdfdd0347bf14d5fc031e9420952f}

# class `HistoryWindow` {#class_history_window}

```
class HistoryWindow
  : public QWidget
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`HistoryWindow`](#class_history_window_1ad545b50ee9a83c213221b3d937252d31)`(const QVector< QVector< QString >> & history,QWidget * parent)` | [HistoryWindow::HistoryWindow](#class_history_window_1ad545b50ee9a83c213221b3d937252d31).
`public  `[`~HistoryWindow`](#class_history_window_1afc23bcc3cd1a50efa9d26bfafedc44b6)`()` | [HistoryWindow::~HistoryWindow](#class_history_window_1afc23bcc3cd1a50efa9d26bfafedc44b6).
`{slot} public void `[`changeOp`](#class_history_window_1aa1baf09cc1f8dfc65b3647ca783cef43)`(int operation)` | [HistoryWindow::changeOp](#class_history_window_1aa1baf09cc1f8dfc65b3647ca783cef43) changes the window's content.
`{slot} public void `[`addMenuHistory`](#class_history_window_1a89fea4903efe8657ad735374255b317e)`()` | [HistoryWindow::addMenuHistory](#class_history_window_1a89fea4903efe8657ad735374255b317e) add entries.

## Members

#### `public  `[`HistoryWindow`](#class_history_window_1ad545b50ee9a83c213221b3d937252d31)`(const QVector< QVector< QString >> & history,QWidget * parent)` {#class_history_window_1ad545b50ee9a83c213221b3d937252d31}

[HistoryWindow::HistoryWindow](#class_history_window_1ad545b50ee9a83c213221b3d937252d31).

#### Parameters
* `history` 

* `parent`

#### `public  `[`~HistoryWindow`](#class_history_window_1afc23bcc3cd1a50efa9d26bfafedc44b6)`()` {#class_history_window_1afc23bcc3cd1a50efa9d26bfafedc44b6}

[HistoryWindow::~HistoryWindow](#class_history_window_1afc23bcc3cd1a50efa9d26bfafedc44b6).

#### `{slot} public void `[`changeOp`](#class_history_window_1aa1baf09cc1f8dfc65b3647ca783cef43)`(int operation)` {#class_history_window_1aa1baf09cc1f8dfc65b3647ca783cef43}

[HistoryWindow::changeOp](#class_history_window_1aa1baf09cc1f8dfc65b3647ca783cef43) changes the window's content.

#### Parameters
* `operation`

#### `{slot} public void `[`addMenuHistory`](#class_history_window_1a89fea4903efe8657ad735374255b317e)`()` {#class_history_window_1a89fea4903efe8657ad735374255b317e}

[HistoryWindow::addMenuHistory](#class_history_window_1a89fea4903efe8657ad735374255b317e) add entries.

# class `HSL` {#class_h_s_l}

```
class HSL
  : public CIExyz
```  

this class uses as base the class [CIExyz](#class_c_i_exyz)[HSL](#class_h_s_l) stores a color in [HSL](#class_h_s_l) representation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`HSL`](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182)`(double h,double s,double l)` | [HSL::HSL](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182) Constructor for [HSL](#class_h_s_l) color representation from double precision numbers.
`public  `[`HSL`](#class_h_s_l_1ae737a28ec6a67bba89090c9a63c5cc21)`(const `[`Color`](#class_color)` * from)` | [HSL::HSL](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182) Constructor for [HSL](#class_h_s_l) color representation from [Color](#class_color) pointer.
`public  `[`HSL`](#class_h_s_l_1a165c0123fc7294e7ccdc53fc11c57154)`(const `[`HSL`](#class_h_s_l)` & from)` | [HSL::HSL](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182) copy constructor.
`public virtual QString `[`getRepresentation`](#class_h_s_l_1a774dc0a5dad87bc9ff44956af4873602)`() const` | HSL::getrepresentation.
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_h_s_l_1af681f885d11220b0588e8f969aa95e32)`() const` | [HSL::negate](#class_h_s_l_1af681f885d11220b0588e8f969aa95e32).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_h_s_l_1a08bcec2ca6961b7c6431d92a625c30a7)`(const `[`Color`](#class_color)` * a) const` | [HSL::mix](#class_h_s_l_1a08bcec2ca6961b7c6431d92a625c30a7).
`public `[`Color`](#class_color)` * `[`getCIE`](#class_h_s_l_1ad755c96eff0cc73dea69c007d745dd4e)`(double h,double s,double l) const` | [HSL::getCIE](#class_h_s_l_1ad755c96eff0cc73dea69c007d745dd4e).
`public virtual QVector< double > `[`getComponents`](#class_h_s_l_1a2de2eb4fa5c9ffcea894f7c6591cb335)`() const` | HSL::getComponent.
`public virtual void `[`setComponents`](#class_h_s_l_1a101be14729707abca388680610e2fe86)`(QVector< double > componets)` | [HSL::setComponents](#class_h_s_l_1a101be14729707abca388680610e2fe86) set the components inside the object.
`public virtual int `[`getNumberOfComponets`](#class_h_s_l_1a6e582f5779c1b5f84abe8bb182a868d0)`() const` | [HSL::getNumberOfComponets](#class_h_s_l_1a6e582f5779c1b5f84abe8bb182a868d0).
`public virtual QVector< QString > `[`getLimits`](#class_h_s_l_1a7ac26d7b7b5755769165455e1b6d3312)`() const` | [HSL::getLimits](#class_h_s_l_1a7ac26d7b7b5755769165455e1b6d3312).

## Members

#### `public  `[`HSL`](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182)`(double h,double s,double l)` {#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182}

[HSL::HSL](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182) Constructor for [HSL](#class_h_s_l) color representation from double precision numbers.

#### Parameters
* `h` 

* `s` 

* `l`

#### `public  `[`HSL`](#class_h_s_l_1ae737a28ec6a67bba89090c9a63c5cc21)`(const `[`Color`](#class_color)` * from)` {#class_h_s_l_1ae737a28ec6a67bba89090c9a63c5cc21}

[HSL::HSL](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182) Constructor for [HSL](#class_h_s_l) color representation from [Color](#class_color) pointer.

#### Parameters
* `from`

#### `public  `[`HSL`](#class_h_s_l_1a165c0123fc7294e7ccdc53fc11c57154)`(const `[`HSL`](#class_h_s_l)` & from)` {#class_h_s_l_1a165c0123fc7294e7ccdc53fc11c57154}

[HSL::HSL](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182) copy constructor.

#### Parameters
* `from`

#### `public virtual QString `[`getRepresentation`](#class_h_s_l_1a774dc0a5dad87bc9ff44956af4873602)`() const` {#class_h_s_l_1a774dc0a5dad87bc9ff44956af4873602}

HSL::getrepresentation.

#### Returns
QString that contains name of the object

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_h_s_l_1af681f885d11220b0588e8f969aa95e32)`() const` {#class_h_s_l_1af681f885d11220b0588e8f969aa95e32}

[HSL::negate](#class_h_s_l_1af681f885d11220b0588e8f969aa95e32).

#### Returns
[Color](#class_color) pointer with a new color with the negated values

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_h_s_l_1a08bcec2ca6961b7c6431d92a625c30a7)`(const `[`Color`](#class_color)` * a) const` {#class_h_s_l_1a08bcec2ca6961b7c6431d92a625c30a7}

[HSL::mix](#class_h_s_l_1a08bcec2ca6961b7c6431d92a625c30a7).

#### Parameters
* `a` 

#### Returns
[Color](#class_color) pointer with a new color mixed as [HSL](#class_h_s_l)

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_h_s_l_1ad755c96eff0cc73dea69c007d745dd4e)`(double h,double s,double l) const` {#class_h_s_l_1ad755c96eff0cc73dea69c007d745dd4e}

[HSL::getCIE](#class_h_s_l_1ad755c96eff0cc73dea69c007d745dd4e).

#### Parameters
* `h` 

* `s` 

* `l` 

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Returns
[Color](#class_color) pointer with a clone of *this in the [CIExyz](#class_c_i_exyz) format

#### `public virtual QVector< double > `[`getComponents`](#class_h_s_l_1a2de2eb4fa5c9ffcea894f7c6591cb335)`() const` {#class_h_s_l_1a2de2eb4fa5c9ffcea894f7c6591cb335}

HSL::getComponent.

#### Returns
QVector<double> with the hue, saturation, lightness component of the color in [HSL](#class_h_s_l)

#### `public virtual void `[`setComponents`](#class_h_s_l_1a101be14729707abca388680610e2fe86)`(QVector< double > componets)` {#class_h_s_l_1a101be14729707abca388680610e2fe86}

[HSL::setComponents](#class_h_s_l_1a101be14729707abca388680610e2fe86) set the components inside the object.

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Parameters
* `componets`

#### `public virtual int `[`getNumberOfComponets`](#class_h_s_l_1a6e582f5779c1b5f84abe8bb182a868d0)`() const` {#class_h_s_l_1a6e582f5779c1b5f84abe8bb182a868d0}

[HSL::getNumberOfComponets](#class_h_s_l_1a6e582f5779c1b5f84abe8bb182a868d0).

#### Returns
int componets number

#### `public virtual QVector< QString > `[`getLimits`](#class_h_s_l_1a7ac26d7b7b5755769165455e1b6d3312)`() const` {#class_h_s_l_1a7ac26d7b7b5755769165455e1b6d3312}

[HSL::getLimits](#class_h_s_l_1a7ac26d7b7b5755769165455e1b6d3312).

#### Returns
limits of [HSL](#class_h_s_l) as QVector<QString>

# class `IllegalColorException` {#class_illegal_color_exception}

```
class IllegalColorException
  : public runtime_error
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`IllegalColorException`](#class_illegal_color_exception_1a2d06f0597577dae21d50835a9e95e531)`(std::string e)` | 

## Members

#### `public inline  `[`IllegalColorException`](#class_illegal_color_exception_1a2d06f0597577dae21d50835a9e95e531)`(std::string e)` {#class_illegal_color_exception_1a2d06f0597577dae21d50835a9e95e531}

# class `MainWindow` {#class_main_window}

```
class MainWindow
  : public View
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`MainWindow`](#class_main_window_1a996c5a2b6f77944776856f08ec30858d)`(QWidget * parent)` | [MainWindow::MainWindow](#class_main_window_1a996c5a2b6f77944776856f08ec30858d) constructor.
`public  `[`~MainWindow`](#class_main_window_1ae98d00a93bc118200eeef9f9bba1dba7)`()` | [MainWindow::MainWindow](#class_main_window_1a996c5a2b6f77944776856f08ec30858d) virtual destructor.
`{slot} public void `[`setLeftTypes`](#class_main_window_1ae065551040ada6411fc1fb4f3887dd3b)`(const QVector< QString > types)` | [MainWindow::setLeftTypes](#class_main_window_1ae065551040ada6411fc1fb4f3887dd3b) add various types to the left drop menu.
`{slot} public void `[`setRightTypes`](#class_main_window_1aca464c6893a9551372c043cb3bf7bf56)`(const QVector< QString > types)` | [MainWindow::setRightTypes](#class_main_window_1aca464c6893a9551372c043cb3bf7bf56) add various types to the right drop menu.
`{slot} public void `[`setResultTypes`](#class_main_window_1a5e2ad194f3764cb9a321b01193c53be9)`(const QVector< QString > types)` | [MainWindow::setResultTypes](#class_main_window_1a5e2ad194f3764cb9a321b01193c53be9) add various types to the result drop menu.
`{slot} public void `[`setLeftFields`](#class_main_window_1a48d094bc4e7965be372f62d2f6e6d910)`(const int & fields,const QVector< QString > & limits)` | [MainWindow::setLeftFields](#class_main_window_1a48d094bc4e7965be372f62d2f6e6d910) add #fields entry lines for the selected left type.
`{slot} public void `[`setRightFields`](#class_main_window_1a8cbaa03b855c6ab3bb7a910662346549)`(const int & fields,const QVector< QString > & limits)` | [MainWindow::setRightFields](#class_main_window_1a8cbaa03b855c6ab3bb7a910662346549) add #fields entry lines for the selected right type.
`{slot} public void `[`setResultFields`](#class_main_window_1ae00d4afec436d34430e43dcc6742b875)`(const int & fields)` | [MainWindow::setResultFields](#class_main_window_1ae00d4afec436d34430e43dcc6742b875) add #fields lines for the result.
`{slot} public void `[`setAvailableOperations`](#class_main_window_1a282ffcc1cb28b83d4f8fe510f6b2e42e)`(const QVector< QString > operations)` | [MainWindow::setAvailableOperations](#class_main_window_1a282ffcc1cb28b83d4f8fe510f6b2e42e) create and connect the given operation to the buttons.
`{slot} public void `[`setPermittedOperations`](#class_main_window_1a86f711960ec362153b5d2ef6667c6c0c)`(const QVector< QString > operations)` | [MainWindow::setPermittedOperations](#class_main_window_1a86f711960ec362153b5d2ef6667c6c0c) toggle the operation buttons that are not aviable for that type.
`{slot} public void `[`setResult`](#class_main_window_1a04fa84f042da5f258d1dc09803667bbf)`(const QVector< QString > result)` | [MainWindow::setResult](#class_main_window_1a04fa84f042da5f258d1dc09803667bbf) shows the recived result in the appropriate line.
`{slot} public void `[`setNumPad`](#class_main_window_1aa16f2c84e4ddda0e0544e1e189b3bc62)`()` | [MainWindow::setNumPad](#class_main_window_1aa16f2c84e4ddda0e0544e1e189b3bc62) set the numbers buttons and the utility buttons, then connect them to the appropriate input.
`{slot} public void `[`setHistory`](#class_main_window_1ace7360a427c4d1b9a5252bd7a468510d)`(const QVector< QVector< QString >> & history)` | [MainWindow::setHistory](#class_main_window_1ace7360a427c4d1b9a5252bd7a468510d) create a new window with history.
`{slot} public void `[`error`](#class_main_window_1a8f2494aee2da70c23aff1c016c6b3225)`(const QString & error_message)` | [MainWindow::error](#class_main_window_1a8f2494aee2da70c23aff1c016c6b3225) create a new window with error message.
`{slot} public void `[`resetType`](#class_main_window_1ae01409cebd6dcebf97ca2f4696fcf542)`(QString drop,QString type)` | [MainWindow::resetType](#class_main_window_1ae01409cebd6dcebf97ca2f4696fcf542).
`{slot} public void `[`show`](#class_main_window_1ae3d7a4598609a86e8bd317c0d85c4495)`()` | [MainWindow::show](#class_main_window_1ae3d7a4598609a86e8bd317c0d85c4495) shows the windows.

## Members

#### `public  `[`MainWindow`](#class_main_window_1a996c5a2b6f77944776856f08ec30858d)`(QWidget * parent)` {#class_main_window_1a996c5a2b6f77944776856f08ec30858d}

[MainWindow::MainWindow](#class_main_window_1a996c5a2b6f77944776856f08ec30858d) constructor.

#### Parameters
* `parent`

#### `public  `[`~MainWindow`](#class_main_window_1ae98d00a93bc118200eeef9f9bba1dba7)`()` {#class_main_window_1ae98d00a93bc118200eeef9f9bba1dba7}

[MainWindow::MainWindow](#class_main_window_1a996c5a2b6f77944776856f08ec30858d) virtual destructor.

#### `{slot} public void `[`setLeftTypes`](#class_main_window_1ae065551040ada6411fc1fb4f3887dd3b)`(const QVector< QString > types)` {#class_main_window_1ae065551040ada6411fc1fb4f3887dd3b}

[MainWindow::setLeftTypes](#class_main_window_1ae065551040ada6411fc1fb4f3887dd3b) add various types to the left drop menu.

#### Parameters
* `types`

#### `{slot} public void `[`setRightTypes`](#class_main_window_1aca464c6893a9551372c043cb3bf7bf56)`(const QVector< QString > types)` {#class_main_window_1aca464c6893a9551372c043cb3bf7bf56}

[MainWindow::setRightTypes](#class_main_window_1aca464c6893a9551372c043cb3bf7bf56) add various types to the right drop menu.

#### Parameters
* `types`

#### `{slot} public void `[`setResultTypes`](#class_main_window_1a5e2ad194f3764cb9a321b01193c53be9)`(const QVector< QString > types)` {#class_main_window_1a5e2ad194f3764cb9a321b01193c53be9}

[MainWindow::setResultTypes](#class_main_window_1a5e2ad194f3764cb9a321b01193c53be9) add various types to the result drop menu.

#### Parameters
* `types`

#### `{slot} public void `[`setLeftFields`](#class_main_window_1a48d094bc4e7965be372f62d2f6e6d910)`(const int & fields,const QVector< QString > & limits)` {#class_main_window_1a48d094bc4e7965be372f62d2f6e6d910}

[MainWindow::setLeftFields](#class_main_window_1a48d094bc4e7965be372f62d2f6e6d910) add #fields entry lines for the selected left type.

#### Parameters
* `fields`

#### `{slot} public void `[`setRightFields`](#class_main_window_1a8cbaa03b855c6ab3bb7a910662346549)`(const int & fields,const QVector< QString > & limits)` {#class_main_window_1a8cbaa03b855c6ab3bb7a910662346549}

[MainWindow::setRightFields](#class_main_window_1a8cbaa03b855c6ab3bb7a910662346549) add #fields entry lines for the selected right type.

#### Parameters
* `fields`

#### `{slot} public void `[`setResultFields`](#class_main_window_1ae00d4afec436d34430e43dcc6742b875)`(const int & fields)` {#class_main_window_1ae00d4afec436d34430e43dcc6742b875}

[MainWindow::setResultFields](#class_main_window_1ae00d4afec436d34430e43dcc6742b875) add #fields lines for the result.

#### Parameters
* `fields`

#### `{slot} public void `[`setAvailableOperations`](#class_main_window_1a282ffcc1cb28b83d4f8fe510f6b2e42e)`(const QVector< QString > operations)` {#class_main_window_1a282ffcc1cb28b83d4f8fe510f6b2e42e}

[MainWindow::setAvailableOperations](#class_main_window_1a282ffcc1cb28b83d4f8fe510f6b2e42e) create and connect the given operation to the buttons.

#### Parameters
* `oplist`

#### `{slot} public void `[`setPermittedOperations`](#class_main_window_1a86f711960ec362153b5d2ef6667c6c0c)`(const QVector< QString > operations)` {#class_main_window_1a86f711960ec362153b5d2ef6667c6c0c}

[MainWindow::setPermittedOperations](#class_main_window_1a86f711960ec362153b5d2ef6667c6c0c) toggle the operation buttons that are not aviable for that type.

#### Parameters
* `operations`

#### `{slot} public void `[`setResult`](#class_main_window_1a04fa84f042da5f258d1dc09803667bbf)`(const QVector< QString > result)` {#class_main_window_1a04fa84f042da5f258d1dc09803667bbf}

[MainWindow::setResult](#class_main_window_1a04fa84f042da5f258d1dc09803667bbf) shows the recived result in the appropriate line.

#### Parameters
* `result`

#### `{slot} public void `[`setNumPad`](#class_main_window_1aa16f2c84e4ddda0e0544e1e189b3bc62)`()` {#class_main_window_1aa16f2c84e4ddda0e0544e1e189b3bc62}

[MainWindow::setNumPad](#class_main_window_1aa16f2c84e4ddda0e0544e1e189b3bc62) set the numbers buttons and the utility buttons, then connect them to the appropriate input.

#### `{slot} public void `[`setHistory`](#class_main_window_1ace7360a427c4d1b9a5252bd7a468510d)`(const QVector< QVector< QString >> & history)` {#class_main_window_1ace7360a427c4d1b9a5252bd7a468510d}

[MainWindow::setHistory](#class_main_window_1ace7360a427c4d1b9a5252bd7a468510d) create a new window with history.

#### Parameters
* `h`

#### `{slot} public void `[`error`](#class_main_window_1a8f2494aee2da70c23aff1c016c6b3225)`(const QString & error_message)` {#class_main_window_1a8f2494aee2da70c23aff1c016c6b3225}

[MainWindow::error](#class_main_window_1a8f2494aee2da70c23aff1c016c6b3225) create a new window with error message.

#### Parameters
* `error_message`

#### `{slot} public void `[`resetType`](#class_main_window_1ae01409cebd6dcebf97ca2f4696fcf542)`(QString drop,QString type)` {#class_main_window_1ae01409cebd6dcebf97ca2f4696fcf542}

[MainWindow::resetType](#class_main_window_1ae01409cebd6dcebf97ca2f4696fcf542).

#### Parameters
* `drop` 

* `type`

#### `{slot} public void `[`show`](#class_main_window_1ae3d7a4598609a86e8bd317c0d85c4495)`()` {#class_main_window_1ae3d7a4598609a86e8bd317c0d85c4495}

[MainWindow::show](#class_main_window_1ae3d7a4598609a86e8bd317c0d85c4495) shows the windows.

# class `MainWindows` {#class_main_windows}

this class uses as base the class [View](#class_view)[MainWindows](#class_main_windows) uses the qt libraries for the GUI

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `Model` {#class_model}

```
class Model
  : public QObject
```  

this abstract class is used by controller to be connected to the view

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public QVector< QString > `[`availableOperations`](#class_model_1a2e34231c9285a6c0a3e3f0c5cd4d51aa)`() const` | 
`public QVector< QString > `[`allAvailableTypes`](#class_model_1ad8efaa1708d2179e4a8e1474cae2df1d)`() const` | 
`public virtual  `[`~Model`](#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` | 
`{signal} public void `[`permittedOperations`](#class_model_1a636cd0b310ee32bd0d7f4a158cb56b6d)`(QVector< QString > operations)` | 
`{signal} public void `[`leftSize`](#class_model_1a533d6dc0f4b7ed4d49f308b689a7747f)`(int size,const QVector< QString > & limits)` | 
`{signal} public void `[`rightSize`](#class_model_1a640b1f4da464ee848601f9122dab5bc4)`(int size,const QVector< QString > & limits)` | 
`{signal} public void `[`rightTypes`](#class_model_1a4019e969fe2996f955d07852f10693dd)`(QVector< QString > permittedTypes)` | 
`{signal} public void `[`resultSize`](#class_model_1a80434fb1d9e3abe82df328164a894e2f)`(int size)` | 
`{signal} public void `[`resultReady`](#class_model_1ae794cf24374d3c78f1b49731d096a077)`(QVector< QString > result)` | 
`{signal} public void `[`history`](#class_model_1a084ed959b9dbdac8f33047916a2b1e9e)`(const QVector< QVector< QString >> & historyVector)` | 
`{signal} public void `[`error`](#class_model_1a1bef8f3d9f6d483c016e3b8d30ea6025)`(QString)` | 
`{signal} public void `[`resetTypeAt`](#class_model_1aa06479997ae88278ab636dc302e1fb70)`(QString drop,QString type)` | 
`{slot} public void `[`setLeftType`](#class_model_1a61d4e70e34d66e77bd508016be6e9637)`(QString type)` | 
`{slot} public void `[`setLeftValues`](#class_model_1ac3c03d44daacd6ad697481c576596592)`(QVector< QString > values)` | 
`{slot} public void `[`setRightType`](#class_model_1a967c3fccc96188c8087b1062045af857)`(QString type)` | 
`{slot} public void `[`setRightValues`](#class_model_1aed3bb530900e322630e2e39eb780991f)`(QVector< QString > values)` | 
`{slot} public void `[`setResultType`](#class_model_1aac934ac17dd66822dbbc074c2d8808b5)`(QString type)` | 
`{slot} public void `[`setOp`](#class_model_1ac58ba62771e20dd87da313b7e399df69)`(QString eOperation)` | 
`{slot} public void `[`execute`](#class_model_1a95509d1e8dd8acff059eec72ac75f496)`()` | 
`{slot} public void `[`getResult`](#class_model_1a00ecb7bd9d19ba145a1ec536539fe08f)`()` | 
`{slot} public void `[`getHistory`](#class_model_1a7328dea3602ce9c290c6821fba74cc6b)`()` | 
`{slot} public void `[`reset`](#class_model_1a6e2f20f21dccde450c3eb1b8eef3126b)`()` | 

## Members

#### `public QVector< QString > `[`availableOperations`](#class_model_1a2e34231c9285a6c0a3e3f0c5cd4d51aa)`() const` {#class_model_1a2e34231c9285a6c0a3e3f0c5cd4d51aa}

#### `public QVector< QString > `[`allAvailableTypes`](#class_model_1ad8efaa1708d2179e4a8e1474cae2df1d)`() const` {#class_model_1ad8efaa1708d2179e4a8e1474cae2df1d}

#### `public virtual  `[`~Model`](#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` {#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6}

#### `{signal} public void `[`permittedOperations`](#class_model_1a636cd0b310ee32bd0d7f4a158cb56b6d)`(QVector< QString > operations)` {#class_model_1a636cd0b310ee32bd0d7f4a158cb56b6d}

#### `{signal} public void `[`leftSize`](#class_model_1a533d6dc0f4b7ed4d49f308b689a7747f)`(int size,const QVector< QString > & limits)` {#class_model_1a533d6dc0f4b7ed4d49f308b689a7747f}

#### `{signal} public void `[`rightSize`](#class_model_1a640b1f4da464ee848601f9122dab5bc4)`(int size,const QVector< QString > & limits)` {#class_model_1a640b1f4da464ee848601f9122dab5bc4}

#### `{signal} public void `[`rightTypes`](#class_model_1a4019e969fe2996f955d07852f10693dd)`(QVector< QString > permittedTypes)` {#class_model_1a4019e969fe2996f955d07852f10693dd}

#### `{signal} public void `[`resultSize`](#class_model_1a80434fb1d9e3abe82df328164a894e2f)`(int size)` {#class_model_1a80434fb1d9e3abe82df328164a894e2f}

#### `{signal} public void `[`resultReady`](#class_model_1ae794cf24374d3c78f1b49731d096a077)`(QVector< QString > result)` {#class_model_1ae794cf24374d3c78f1b49731d096a077}

#### `{signal} public void `[`history`](#class_model_1a084ed959b9dbdac8f33047916a2b1e9e)`(const QVector< QVector< QString >> & historyVector)` {#class_model_1a084ed959b9dbdac8f33047916a2b1e9e}

#### `{signal} public void `[`error`](#class_model_1a1bef8f3d9f6d483c016e3b8d30ea6025)`(QString)` {#class_model_1a1bef8f3d9f6d483c016e3b8d30ea6025}

#### `{signal} public void `[`resetTypeAt`](#class_model_1aa06479997ae88278ab636dc302e1fb70)`(QString drop,QString type)` {#class_model_1aa06479997ae88278ab636dc302e1fb70}

#### `{slot} public void `[`setLeftType`](#class_model_1a61d4e70e34d66e77bd508016be6e9637)`(QString type)` {#class_model_1a61d4e70e34d66e77bd508016be6e9637}

#### `{slot} public void `[`setLeftValues`](#class_model_1ac3c03d44daacd6ad697481c576596592)`(QVector< QString > values)` {#class_model_1ac3c03d44daacd6ad697481c576596592}

#### `{slot} public void `[`setRightType`](#class_model_1a967c3fccc96188c8087b1062045af857)`(QString type)` {#class_model_1a967c3fccc96188c8087b1062045af857}

#### `{slot} public void `[`setRightValues`](#class_model_1aed3bb530900e322630e2e39eb780991f)`(QVector< QString > values)` {#class_model_1aed3bb530900e322630e2e39eb780991f}

#### `{slot} public void `[`setResultType`](#class_model_1aac934ac17dd66822dbbc074c2d8808b5)`(QString type)` {#class_model_1aac934ac17dd66822dbbc074c2d8808b5}

#### `{slot} public void `[`setOp`](#class_model_1ac58ba62771e20dd87da313b7e399df69)`(QString eOperation)` {#class_model_1ac58ba62771e20dd87da313b7e399df69}

#### `{slot} public void `[`execute`](#class_model_1a95509d1e8dd8acff059eec72ac75f496)`()` {#class_model_1a95509d1e8dd8acff059eec72ac75f496}

#### `{slot} public void `[`getResult`](#class_model_1a00ecb7bd9d19ba145a1ec536539fe08f)`()` {#class_model_1a00ecb7bd9d19ba145a1ec536539fe08f}

#### `{slot} public void `[`getHistory`](#class_model_1a7328dea3602ce9c290c6821fba74cc6b)`()` {#class_model_1a7328dea3602ce9c290c6821fba74cc6b}

#### `{slot} public void `[`reset`](#class_model_1a6e2f20f21dccde450c3eb1b8eef3126b)`()` {#class_model_1a6e2f20f21dccde450c3eb1b8eef3126b}

# class `RGB` {#class_r_g_b}

```
class RGB
  : public CIExyz
```  

this class uses the as base class [CIExyz](#class_c_i_exyz)[RGB](#class_r_g_b) stores a color in [RGB](#class_r_g_b) representation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`RGB`](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001)`(int r,int g,int b)` | [RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).
`public  `[`RGB`](#class_r_g_b_1a4b69fccf264945ab5d708738824bd93a)`(const `[`RGB`](#class_r_g_b)` & c)` | [RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).
`public  `[`RGB`](#class_r_g_b_1a9caf6caec9c6e67896b24ba3a1715342)`(const `[`RGB`](#class_r_g_b)` * c)` | [RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).
`public  `[`RGB`](#class_r_g_b_1acabd7e004d54445c5e87f27fcd06ad33)`(const `[`Color`](#class_color)` * c)` | [RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).
`public  `[`~RGB`](#class_r_g_b_1a2f89f461b43bc3036dafbc899e8204f5)`() = default` | 
`public virtual `[`Color`](#class_color)` * `[`getCIE`](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24)`() const` | [RGB::getCIE](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24).
`public virtual void `[`setComponents`](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36)`(QVector< double > componets)` | [RGB::setComponents](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36) set the components inside the object.
`public virtual QString `[`getRepresentation`](#class_r_g_b_1a5f7a68904e1e4f18c22c1066170fb2bf)`() const` | RGB::getrepresentation returns the meaning of the values contained in [getComponents()](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769)
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69)`() const` | [RGB::negate](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9)`(const `[`Color`](#class_color)` * c) const` | [RGB::mix](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9).
`public virtual `[`Color`](#class_color)` * `[`operator/`](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80)`(const int & div) const` | [RGB::operator /](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80) new [RGB](#class_r_g_b) object with value divided.
`public virtual QVector< QString > `[`availableOperations`](#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4)`() const` | [RGB::availableOperations](#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4) returns all the operation that has been implemented.
`public virtual QVector< double > `[`getComponents`](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769)`() const` | [RGB::getComponents](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769);.
`public virtual int `[`getNumberOfComponets`](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345)`() const` | [RGB::getNumberOfComponets](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345).
`public virtual QVector< QString > `[`getLimits`](#class_r_g_b_1a4ae8d5c061e45f557a5924f2237c1d0e)`() const` | [RGB::getLimits](#class_r_g_b_1a4ae8d5c061e45f557a5924f2237c1d0e).
`public `[`CIExyz`](#class_c_i_exyz)` * `[`getCIE`](#class_r_g_b_1a153f315167dfd89944c625d43b307b43)`(int t_r,int t_g,int t_b) const` | [RGB::getCIE](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24) converts [RGB](#class_r_g_b) value to [CIExyz](#class_c_i_exyz).

## Members

#### `public  `[`RGB`](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001)`(int r,int g,int b)` {#class_r_g_b_1ab48fc0751f6432ff993b31119f289001}

[RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).

#### Parameters
* `int` t_r 

* `int` t_g 

* `int` t_b 

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` uses the local function getCIE(int t_r, int t_g, int t_b) to inizialize the parent object and set the local array values to rgb in input order

#### `public  `[`RGB`](#class_r_g_b_1a4b69fccf264945ab5d708738824bd93a)`(const `[`RGB`](#class_r_g_b)` & c)` {#class_r_g_b_1a4b69fccf264945ab5d708738824bd93a}

[RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).

#### Parameters
* `RGB&` t_c Constructor that takes a [RGB](#class_r_g_b) pointer and clones the object

#### `public  `[`RGB`](#class_r_g_b_1a9caf6caec9c6e67896b24ba3a1715342)`(const `[`RGB`](#class_r_g_b)` * c)` {#class_r_g_b_1a9caf6caec9c6e67896b24ba3a1715342}

[RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).

#### Parameters
* `RGB*` t_c

#### `public  `[`RGB`](#class_r_g_b_1acabd7e004d54445c5e87f27fcd06ad33)`(const `[`Color`](#class_color)` * c)` {#class_r_g_b_1acabd7e004d54445c5e87f27fcd06ad33}

[RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).

#### Parameters
* `Color*` t_c Constructor for [RGB](#class_r_g_b) that get a [Color](#class_color) pointer And inzialize parent objcet with a clone of [CIExyz](#class_c_i_exyz) representation

#### `public  `[`~RGB`](#class_r_g_b_1a2f89f461b43bc3036dafbc899e8204f5)`() = default` {#class_r_g_b_1a2f89f461b43bc3036dafbc899e8204f5}

#### `public virtual `[`Color`](#class_color)` * `[`getCIE`](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24)`() const` {#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24}

[RGB::getCIE](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24).

#### Returns
a new [Color](#class_color) object as [CIExyz](#class_c_i_exyz)

#### `public virtual void `[`setComponents`](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36)`(QVector< double > componets)` {#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36}

[RGB::setComponents](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36) set the components inside the object.

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Parameters
* `componets`

#### `public virtual QString `[`getRepresentation`](#class_r_g_b_1a5f7a68904e1e4f18c22c1066170fb2bf)`() const` {#class_r_g_b_1a5f7a68904e1e4f18c22c1066170fb2bf}

RGB::getrepresentation returns the meaning of the values contained in [getComponents()](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769)

#### Returns
QString that contains name of the object

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69)`() const` {#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69}

[RGB::negate](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69).

#### Returns
return a new [Color](#class_color) object with a new negated color as [RGB](#class_r_g_b)

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9)`(const `[`Color`](#class_color)` * c) const` {#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9}

[RGB::mix](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9).

#### Parameters
* `Color*` t_c 

#### Returns
a new [Color](#class_color) object with the mixed Colors as [RGB](#class_r_g_b)

#### `public virtual `[`Color`](#class_color)` * `[`operator/`](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80)`(const int & div) const` {#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80}

[RGB::operator /](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80) new [RGB](#class_r_g_b) object with value divided.

#### Parameters
* `int` div 

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Returns
[RGB](#class_r_g_b)

#### `public virtual QVector< QString > `[`availableOperations`](#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4)`() const` {#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4}

[RGB::availableOperations](#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4) returns all the operation that has been implemented.

#### Returns
QVector<QString>

#### `public virtual QVector< double > `[`getComponents`](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769)`() const` {#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769}

[RGB::getComponents](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769);.

#### Returns
components in a QVector<double>

#### `public virtual int `[`getNumberOfComponets`](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345)`() const` {#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345}

[RGB::getNumberOfComponets](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345).

#### Returns
int

#### `public virtual QVector< QString > `[`getLimits`](#class_r_g_b_1a4ae8d5c061e45f557a5924f2237c1d0e)`() const` {#class_r_g_b_1a4ae8d5c061e45f557a5924f2237c1d0e}

[RGB::getLimits](#class_r_g_b_1a4ae8d5c061e45f557a5924f2237c1d0e).

#### Returns
[RGB](#class_r_g_b) limits as QVector<QString>

#### `public `[`CIExyz`](#class_c_i_exyz)` * `[`getCIE`](#class_r_g_b_1a153f315167dfd89944c625d43b307b43)`(int t_r,int t_g,int t_b) const` {#class_r_g_b_1a153f315167dfd89944c625d43b307b43}

[RGB::getCIE](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24) converts [RGB](#class_r_g_b) value to [CIExyz](#class_c_i_exyz).

#### Parameters
* `int` t_r 

* `int` t_g 

* `int` t_b 

#### Returns
a new [Color](#class_color) object as CIExyz*

# class `View` {#class_view}

```
class View
  : public QWidget
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`View`](#class_view_1a3fd5b2cd3d7ccfc51dd4b2730833180c)`(QWidget * parent)` | 
`public virtual  `[`~View`](#class_view_1ad0f3ade04bca4e74b8868e63729bad86)`() = default` | 
`{signal} public void `[`leftValuesAreSet`](#class_view_1a96f2fd0ed3467a0e5072e9a4a5593395)`(QVector< QString > values)` | 
`{signal} public void `[`rightValuesAreSet`](#class_view_1aef26164c727b9a1b83ca0e84c00a0060)`(QVector< QString > values)` | 
`{signal} public void `[`leftTypeIsSet`](#class_view_1ae0775d09884cd6b001829df4276e407c)`(QString type)` | 
`{signal} public void `[`rightTypeIsSet`](#class_view_1a29e8b493fdbca2747da4ffa855ab966c)`(QString type)` | 
`{signal} public void `[`resultTypeIsSet`](#class_view_1aa510baf4ace905a146c2655ca4a4b55e)`(QString type)` | 
`{signal} public void `[`operationIsSet`](#class_view_1af4cf1863986a0fac18d6da46c97329de)`(QString opt)` | 
`{signal} public void `[`getResult`](#class_view_1ac05f93e75953488aa1a5a3f813603032)`()` | 
`{signal} public void `[`getHistory`](#class_view_1a0cf275613b9eb5cc57e2069df61a87e1)`()` | 
`{signal} public void `[`reset`](#class_view_1a84eea48d2036da09640369d7997d957b)`()` | 
`{signal} public void `[`done`](#class_view_1af0a5104e717bfe94ae35a1dfd9d5e183)`()` | 
`{slot} public void `[`setAvailableOperations`](#class_view_1a203ab36b8546f1d9dc630bd7c0536e67)`(const QVector< QString > operations)` | 
`{slot} public void `[`setPermittedOperations`](#class_view_1a5b3c08e11f2aece6c28c9b36e41ae35a)`(const QVector< QString > operations)` | 
`{slot} public void `[`setLeftTypes`](#class_view_1a80c90f9167a8bc834d8c2f25be9e5f0d)`(const QVector< QString > types)` | 
`{slot} public void `[`setLeftFields`](#class_view_1a497493954a4a2be8cf50306a884d7358)`(const int & fields,const QVector< QString > & limits)` | 
`{slot} public void `[`setRightTypes`](#class_view_1a26bb1996d32f29476ba3c0b5c01561fc)`(const QVector< QString > types)` | 
`{slot} public void `[`setRightFields`](#class_view_1a342210db03ff75bfe4b66f3383e50341)`(const int & fields,const QVector< QString > & limits)` | 
`{slot} public void `[`setResult`](#class_view_1a2d78db2bd23a6dd80bfeae64f4c3fdd3)`(const QVector< QString > result)` | 
`{slot} public void `[`setResultFields`](#class_view_1ad3f5b700bd33a72bebc6efdbad2d17eb)`(const int & fields)` | 
`{slot} public void `[`setHistory`](#class_view_1a3d017128dbceb8a10e0c35fcd852e987)`(const QVector< QVector< QString >> & history)` | 
`{slot} public void `[`error`](#class_view_1a117a5d1b3b3e3823e628d859f6f3cb48)`(const QString & error_message)` | 
`{slot} public void `[`resetType`](#class_view_1a0fd83f152fae6bbcaf6537f4379fd15b)`(QString drop,QString type)` | 
`{slot} public void `[`show`](#class_view_1a913b840fc8042436555b89878feacb76)`()` | 

## Members

#### `public inline  `[`View`](#class_view_1a3fd5b2cd3d7ccfc51dd4b2730833180c)`(QWidget * parent)` {#class_view_1a3fd5b2cd3d7ccfc51dd4b2730833180c}

#### `public virtual  `[`~View`](#class_view_1ad0f3ade04bca4e74b8868e63729bad86)`() = default` {#class_view_1ad0f3ade04bca4e74b8868e63729bad86}

#### `{signal} public void `[`leftValuesAreSet`](#class_view_1a96f2fd0ed3467a0e5072e9a4a5593395)`(QVector< QString > values)` {#class_view_1a96f2fd0ed3467a0e5072e9a4a5593395}

#### `{signal} public void `[`rightValuesAreSet`](#class_view_1aef26164c727b9a1b83ca0e84c00a0060)`(QVector< QString > values)` {#class_view_1aef26164c727b9a1b83ca0e84c00a0060}

#### `{signal} public void `[`leftTypeIsSet`](#class_view_1ae0775d09884cd6b001829df4276e407c)`(QString type)` {#class_view_1ae0775d09884cd6b001829df4276e407c}

#### `{signal} public void `[`rightTypeIsSet`](#class_view_1a29e8b493fdbca2747da4ffa855ab966c)`(QString type)` {#class_view_1a29e8b493fdbca2747da4ffa855ab966c}

#### `{signal} public void `[`resultTypeIsSet`](#class_view_1aa510baf4ace905a146c2655ca4a4b55e)`(QString type)` {#class_view_1aa510baf4ace905a146c2655ca4a4b55e}

#### `{signal} public void `[`operationIsSet`](#class_view_1af4cf1863986a0fac18d6da46c97329de)`(QString opt)` {#class_view_1af4cf1863986a0fac18d6da46c97329de}

#### `{signal} public void `[`getResult`](#class_view_1ac05f93e75953488aa1a5a3f813603032)`()` {#class_view_1ac05f93e75953488aa1a5a3f813603032}

#### `{signal} public void `[`getHistory`](#class_view_1a0cf275613b9eb5cc57e2069df61a87e1)`()` {#class_view_1a0cf275613b9eb5cc57e2069df61a87e1}

#### `{signal} public void `[`reset`](#class_view_1a84eea48d2036da09640369d7997d957b)`()` {#class_view_1a84eea48d2036da09640369d7997d957b}

#### `{signal} public void `[`done`](#class_view_1af0a5104e717bfe94ae35a1dfd9d5e183)`()` {#class_view_1af0a5104e717bfe94ae35a1dfd9d5e183}

#### `{slot} public void `[`setAvailableOperations`](#class_view_1a203ab36b8546f1d9dc630bd7c0536e67)`(const QVector< QString > operations)` {#class_view_1a203ab36b8546f1d9dc630bd7c0536e67}

#### `{slot} public void `[`setPermittedOperations`](#class_view_1a5b3c08e11f2aece6c28c9b36e41ae35a)`(const QVector< QString > operations)` {#class_view_1a5b3c08e11f2aece6c28c9b36e41ae35a}

#### `{slot} public void `[`setLeftTypes`](#class_view_1a80c90f9167a8bc834d8c2f25be9e5f0d)`(const QVector< QString > types)` {#class_view_1a80c90f9167a8bc834d8c2f25be9e5f0d}

#### `{slot} public void `[`setLeftFields`](#class_view_1a497493954a4a2be8cf50306a884d7358)`(const int & fields,const QVector< QString > & limits)` {#class_view_1a497493954a4a2be8cf50306a884d7358}

#### `{slot} public void `[`setRightTypes`](#class_view_1a26bb1996d32f29476ba3c0b5c01561fc)`(const QVector< QString > types)` {#class_view_1a26bb1996d32f29476ba3c0b5c01561fc}

#### `{slot} public void `[`setRightFields`](#class_view_1a342210db03ff75bfe4b66f3383e50341)`(const int & fields,const QVector< QString > & limits)` {#class_view_1a342210db03ff75bfe4b66f3383e50341}

#### `{slot} public void `[`setResult`](#class_view_1a2d78db2bd23a6dd80bfeae64f4c3fdd3)`(const QVector< QString > result)` {#class_view_1a2d78db2bd23a6dd80bfeae64f4c3fdd3}

#### `{slot} public void `[`setResultFields`](#class_view_1ad3f5b700bd33a72bebc6efdbad2d17eb)`(const int & fields)` {#class_view_1ad3f5b700bd33a72bebc6efdbad2d17eb}

#### `{slot} public void `[`setHistory`](#class_view_1a3d017128dbceb8a10e0c35fcd852e987)`(const QVector< QVector< QString >> & history)` {#class_view_1a3d017128dbceb8a10e0c35fcd852e987}

#### `{slot} public void `[`error`](#class_view_1a117a5d1b3b3e3823e628d859f6f3cb48)`(const QString & error_message)` {#class_view_1a117a5d1b3b3e3823e628d859f6f3cb48}

#### `{slot} public void `[`resetType`](#class_view_1a0fd83f152fae6bbcaf6537f4379fd15b)`(QString drop,QString type)` {#class_view_1a0fd83f152fae6bbcaf6537f4379fd15b}

#### `{slot} public void `[`show`](#class_view_1a913b840fc8042436555b89878feacb76)`()` {#class_view_1a913b840fc8042436555b89878feacb76}

# class `YUV` {#class_y_u_v}

```
class YUV
  : public RGB
```  

this class uses as base the class [RGB](#class_r_g_b)[YUV](#class_y_u_v) stores a color in [YUV](#class_y_u_v) representation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`YUV`](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84)`(double _y,double _u,double _v)` | [YUV::YUV](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84) Constructor for [YUV](#class_y_u_v) color representation from double precision numbers.
`public  `[`YUV`](#class_y_u_v_1a80778948bf90243f1424e06f9dfbbbf1)`(const `[`Color`](#class_color)` * from)` | [YUV::YUV](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84) Constructor for [YUV](#class_y_u_v) color representation from [Color](#class_color) pointer.
`public  `[`YUV`](#class_y_u_v_1af6de31964471999a64e34af00ef6e196)`(const `[`YUV`](#class_y_u_v)` & from)` | [YUV::YUV](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84) copy constructor.
`public virtual QString `[`getRepresentation`](#class_y_u_v_1ae38403ffd397003eb28ab7670f95d1e5)`() const` | YUV::getrepresentation.
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_y_u_v_1a079872ae88552066ce1abb39cc0a40de)`() const` | [YUV::negate](#class_y_u_v_1a079872ae88552066ce1abb39cc0a40de).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_y_u_v_1ab152a4ea37eaa67df0b38882c2099da3)`(const `[`Color`](#class_color)` * a) const` | [YUV::mix](#class_y_u_v_1ab152a4ea37eaa67df0b38882c2099da3).
`public `[`Color`](#class_color)` * `[`getCIE`](#class_y_u_v_1a56f11c27f1659c30ebd20c929704e004)`(double y,double u,double v)` | [YUV::getCIE](#class_y_u_v_1a56f11c27f1659c30ebd20c929704e004).
`public virtual QVector< double > `[`getComponents`](#class_y_u_v_1ad90109db3486e61e248e274a7690824a)`() const` | YUV::getComponent.
`public virtual int `[`getNumberOfComponets`](#class_y_u_v_1a46eded5c13a0c2b2e9bbf05d4a2f9c7c)`() const` | [YUV::getNumberOfComponets](#class_y_u_v_1a46eded5c13a0c2b2e9bbf05d4a2f9c7c).
`public virtual void `[`setComponents`](#class_y_u_v_1a622daf7a688da4a227b63deb412c0d46)`(QVector< double > componets)` | [YUV::setComponents](#class_y_u_v_1a622daf7a688da4a227b63deb412c0d46) set the components inside the object.
`public virtual `[`Color`](#class_color)` * `[`operator/`](#class_y_u_v_1a1b9300c00323eca16fc4bb028964e85f)`(const int & div) const` | [YUV::operator /](#class_y_u_v_1a1b9300c00323eca16fc4bb028964e85f).
`public virtual QVector< QString > `[`getLimits`](#class_y_u_v_1a344cd573b663c97f5554afcb1c15458c)`() const` | [YUV::getLimits](#class_y_u_v_1a344cd573b663c97f5554afcb1c15458c).

## Members

#### `public  `[`YUV`](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84)`(double _y,double _u,double _v)` {#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84}

[YUV::YUV](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84) Constructor for [YUV](#class_y_u_v) color representation from double precision numbers.

#### Parameters
* `_y` 

* `_u` 

* `_v`

#### `public  `[`YUV`](#class_y_u_v_1a80778948bf90243f1424e06f9dfbbbf1)`(const `[`Color`](#class_color)` * from)` {#class_y_u_v_1a80778948bf90243f1424e06f9dfbbbf1}

[YUV::YUV](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84) Constructor for [YUV](#class_y_u_v) color representation from [Color](#class_color) pointer.

#### Exceptions
* `[IllegalColorException](#class_illegal_color_exception)` 

#### Parameters
* `from`

#### `public  `[`YUV`](#class_y_u_v_1af6de31964471999a64e34af00ef6e196)`(const `[`YUV`](#class_y_u_v)` & from)` {#class_y_u_v_1af6de31964471999a64e34af00ef6e196}

[YUV::YUV](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84) copy constructor.

#### Parameters
* `from`

#### `public virtual QString `[`getRepresentation`](#class_y_u_v_1ae38403ffd397003eb28ab7670f95d1e5)`() const` {#class_y_u_v_1ae38403ffd397003eb28ab7670f95d1e5}

YUV::getrepresentation.

#### Returns
QString that contains the name

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_y_u_v_1a079872ae88552066ce1abb39cc0a40de)`() const` {#class_y_u_v_1a079872ae88552066ce1abb39cc0a40de}

[YUV::negate](#class_y_u_v_1a079872ae88552066ce1abb39cc0a40de).

#### Returns
[Color](#class_color) pointer with a new color with the negated values

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_y_u_v_1ab152a4ea37eaa67df0b38882c2099da3)`(const `[`Color`](#class_color)` * a) const` {#class_y_u_v_1ab152a4ea37eaa67df0b38882c2099da3}

[YUV::mix](#class_y_u_v_1ab152a4ea37eaa67df0b38882c2099da3).

#### Parameters
* `a` 

#### Returns
[Color](#class_color) pointer with a new Object color mixed

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_y_u_v_1a56f11c27f1659c30ebd20c929704e004)`(double y,double u,double v)` {#class_y_u_v_1a56f11c27f1659c30ebd20c929704e004}

[YUV::getCIE](#class_y_u_v_1a56f11c27f1659c30ebd20c929704e004).

#### Parameters
* `y` 

* `u` 

* `v` 

#### Returns
[Color](#class_color) pointer with a clone of *this in the [CIExyz](#class_c_i_exyz) format

#### `public virtual QVector< double > `[`getComponents`](#class_y_u_v_1ad90109db3486e61e248e274a7690824a)`() const` {#class_y_u_v_1ad90109db3486e61e248e274a7690824a}

YUV::getComponent.

#### Returns
QVector<double> with the y, u, v component of the color in [YUV](#class_y_u_v)

#### `public virtual int `[`getNumberOfComponets`](#class_y_u_v_1a46eded5c13a0c2b2e9bbf05d4a2f9c7c)`() const` {#class_y_u_v_1a46eded5c13a0c2b2e9bbf05d4a2f9c7c}

[YUV::getNumberOfComponets](#class_y_u_v_1a46eded5c13a0c2b2e9bbf05d4a2f9c7c).

#### Returns
int componets number

#### `public virtual void `[`setComponents`](#class_y_u_v_1a622daf7a688da4a227b63deb412c0d46)`(QVector< double > componets)` {#class_y_u_v_1a622daf7a688da4a227b63deb412c0d46}

[YUV::setComponents](#class_y_u_v_1a622daf7a688da4a227b63deb412c0d46) set the components inside the object.

#### Parameters
* `componets`

#### `public virtual `[`Color`](#class_color)` * `[`operator/`](#class_y_u_v_1a1b9300c00323eca16fc4bb028964e85f)`(const int & div) const` {#class_y_u_v_1a1b9300c00323eca16fc4bb028964e85f}

[YUV::operator /](#class_y_u_v_1a1b9300c00323eca16fc4bb028964e85f).

#### Parameters
* `div` 

#### Returns
[Color](#class_color) pointer with a new Object color

#### `public virtual QVector< QString > `[`getLimits`](#class_y_u_v_1a344cd573b663c97f5554afcb1c15458c)`() const` {#class_y_u_v_1a344cd573b663c97f5554afcb1c15458c}

[YUV::getLimits](#class_y_u_v_1a344cd573b663c97f5554afcb1c15458c).

#### Returns
limits in QVector<QString>

Generated by [Moxygen](https://sourcey.com/moxygen)