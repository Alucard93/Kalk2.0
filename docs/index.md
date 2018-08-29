# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public int `[`main`](#main_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)`            | 
`class `[`CIExyz`](#class_c_i_exyz) | this class uses the base class color and stores a color in CIE xyz rappresentation
`class `[`Color`](#class_color) | this class it the main base for color rappresentation in this program
`class `[`ColorFactory`](#class_color_factory) | this class stores all Factories, initializes a New [Color](#class_color) object when required, returns what kind of operation can be done with a specific color rappresentation and returs the result using the permitted operations
`class `[`ColorModel`](#class_color_model) | 
`class `[`ConsoleView`](#class_console_view) | [ConsoleView](#class_console_view) exestends the [View](#class_view) class and provides an interface in terminal line.
`class `[`Controller`](#class_controller) | 
`class `[`CYMK`](#class_c_y_m_k) | 
`class `[`Factory`](#class_factory) | 
`class `[`Factory< T >`](#class_factory_3_01_t_01_4) | this class extends [GenericFactory](#class_generic_factory) and implements getNewColor() inizializes the map allColorFactories in [ColorFactory](#class_color_factory) and makes available to [ColorFactory](#class_color_factory) a constructor for the new color requested
`class `[`GenericFactory`](#class_generic_factory) | 
`class `[`HSL`](#class_h_s_l) | 
`class `[`IllegalColorException`](#class_illegal_color_exception) | 
`class `[`MainWindow`](#class_main_window) | 
`class `[`Model`](#class_model) | 
`class `[`RGB`](#class_r_g_b) | this class uses the as base class [CIExyz](#class_c_i_exyz) and stores a color in [RGB](#class_r_g_b) rappresentation
`class `[`View`](#class_view) | 
`class `[`YCbCr`](#class_y_cb_cr) | 
`class `[`YUV`](#class_y_u_v) | 

## Members

#### `public int `[`main`](#main_8cpp_1a0ddf1224851353fc92bfbff6f499fa97)`(int argc,char * argv)` 

# class `CIExyz` 

```
class CIExyz
  : public Color
```  

this class uses the base class color and stores a color in CIE xyz rappresentation

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CIExyz`](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90)`(double t_x,double t_y,double t_z)` | [CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) Constructor for CIE xyz color rappresentation from double precision numbers.
`public  `[`CIExyz`](#class_c_i_exyz_1aa16b12dfc4f0ceac557778e5bede454c)`(const `[`CIExyz`](#class_c_i_exyz)` & c)` | [CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) copy constructor.
`public  `[`CIExyz`](#class_c_i_exyz_1a861692ec98ae70d205cbee47fc63a879)`(const `[`Color`](#class_color)` * c)` | [CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) Constructor for CIE xyz color rappresentation from [Color](#class_color) pointer.
`public  `[`~CIExyz`](#class_c_i_exyz_1a13c440b1fa97445914886573eeed5428)`() = default` | 
`public virtual int `[`getNumberOfComponets`](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e)`() const` | [CIExyz::getNumberOfComponets](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e).
`public virtual void `[`setComponents`](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84)`(QVector< double > componets)` | [CIExyz::setComponents](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84) set the components inside the object.
`public virtual QString `[`getRappresentation`](#class_c_i_exyz_1a116a1e50a9399db86333f02a8961c2d1)`() const` | [CIExyz::getRappresentation](#class_c_i_exyz_1a116a1e50a9399db86333f02a8961c2d1).
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94)`() const` | [CIExyz::negate](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8)`(const `[`Color`](#class_color)` * c) const` | [CIExyz::mix](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8).
`public virtual `[`Color`](#class_color)` * `[`getCIE`](#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b)`() const` | [CIExyz::getCIE](#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b).
`public virtual `[`Color`](#class_color)` * `[`operator/`](#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa)`(const int & div) const` | [CIExyz::operator /](#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa).
`public virtual QVector< QString > `[`availableOperations`](#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1)`() const` | [CIExyz::availableOperations](#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1).
`public virtual QVector< double > `[`getComponents`](#class_c_i_exyz_1af8992e3ac1741c35fcb18aa2cdb554a0)`() const` | CIExyz::getComponent.

## Members

#### `public  `[`CIExyz`](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90)`(double t_x,double t_y,double t_z)` 

[CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) Constructor for CIE xyz color rappresentation from double precision numbers.

#### Parameters
* `t_x` 

* `t_y` 

* `t_z`

#### `public  `[`CIExyz`](#class_c_i_exyz_1aa16b12dfc4f0ceac557778e5bede454c)`(const `[`CIExyz`](#class_c_i_exyz)` & c)` 

[CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) copy constructor.

#### Parameters
* `c`

#### `public  `[`CIExyz`](#class_c_i_exyz_1a861692ec98ae70d205cbee47fc63a879)`(const `[`Color`](#class_color)` * c)` 

[CIExyz::CIExyz](#class_c_i_exyz_1aea8a8b567ac89a96b0bf4c749a49ea90) Constructor for CIE xyz color rappresentation from [Color](#class_color) pointer.

#### Parameters
* `c`

#### `public  `[`~CIExyz`](#class_c_i_exyz_1a13c440b1fa97445914886573eeed5428)`() = default` 

#### `public virtual int `[`getNumberOfComponets`](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e)`() const` 

[CIExyz::getNumberOfComponets](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e).

#### Returns
int componets number

#### `public virtual void `[`setComponents`](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84)`(QVector< double > componets)` 

[CIExyz::setComponents](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84) set the components inside the object.

#### Parameters
* `componets`

#### `public virtual QString `[`getRappresentation`](#class_c_i_exyz_1a116a1e50a9399db86333f02a8961c2d1)`() const` 

[CIExyz::getRappresentation](#class_c_i_exyz_1a116a1e50a9399db86333f02a8961c2d1).

#### Returns
QString that contains the meaning of the values contained in [getComponents()](#class_c_i_exyz_1af8992e3ac1741c35fcb18aa2cdb554a0)

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94)`() const` 

[CIExyz::negate](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94).

#### Returns
[Color](#class_color) pointer with a new color with the complementar values

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8)`(const `[`Color`](#class_color)` * c) const` 

[CIExyz::mix](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8).

#### Parameters
* `c` 

#### Returns
[Color](#class_color) pointer with a new Object color mixed

#### `public virtual `[`Color`](#class_color)` * `[`getCIE`](#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b)`() const` 

[CIExyz::getCIE](#class_c_i_exyz_1aa93c7a293b63c7bce8d1fab9a185ab1b).

#### Returns
[Color](#class_color) pointer with a clone of *this

#### `public virtual `[`Color`](#class_color)` * `[`operator/`](#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa)`(const int & div) const` 

[CIExyz::operator /](#class_c_i_exyz_1abb3f5e1c8a923d7758e6bbe83b71f4fa).

#### Exceptions
* `[IllegalColorException("operation](#class_illegal_color_exception)` not available");

#### `public virtual QVector< QString > `[`availableOperations`](#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1)`() const` 

[CIExyz::availableOperations](#class_c_i_exyz_1aa82a27c78ff425e06cdd740dd50e93b1).

#### Returns
all the operation that has been implemented

#### `public virtual QVector< double > `[`getComponents`](#class_c_i_exyz_1af8992e3ac1741c35fcb18aa2cdb554a0)`() const` 

CIExyz::getComponent.

#### Returns
QVector<double> with the x y z component of the color in CIE XYZ

# class `Color` 

this class it the main base for color rappresentation in this program

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
`public QVector< QString > `[`availableOperations`](#class_color_1af521a40fabd5e4718ada6531fc20ec58)`() const` | 
`public QVector< double > `[`getComponents`](#class_color_1a0c30989b24589c8725abe286cc5e7a23)`() const` | 
`public QString `[`getRappresentation`](#class_color_1ad8bc1039f9f74b9a9e5e59c669d6d6e9)`() const` | 

## Members

#### `public  `[`Color`](#class_color_1a6fae8aa8b75d27cb134234e75b41caf2)`() = default` 

#### `public virtual  `[`~Color`](#class_color_1a2c0b567ad3430b6fe40f8b06c12654eb)`() = default` 

#### `public int `[`getNumberOfComponets`](#class_color_1a0e16ae80374851824e791a941c6315e1)`() const` 

#### `public void `[`setComponents`](#class_color_1a84ee279d59516539f2940a424018c376)`(QVector< double > componets)` 

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_color_1a5d360ee273c34bceb8dd5837489a0a18)`() const` 

#### `public `[`Color`](#class_color)` * `[`negate`](#class_color_1aa73035295e3e42593b11904c398f1657)`() const` 

#### `public `[`Color`](#class_color)` * `[`mix`](#class_color_1ab240ddb0e1d4779703f6b2ee35a8a0e9)`(const `[`Color`](#class_color)` * c1) const` 

#### `public `[`Color`](#class_color)` * `[`operator/`](#class_color_1acb25591213c391f682c9261c85dc111c)`(const int & div) const` 

#### `public QVector< QString > `[`availableOperations`](#class_color_1af521a40fabd5e4718ada6531fc20ec58)`() const` 

#### `public QVector< double > `[`getComponents`](#class_color_1a0c30989b24589c8725abe286cc5e7a23)`() const` 

#### `public QString `[`getRappresentation`](#class_color_1ad8bc1039f9f74b9a9e5e59c669d6d6e9)`() const` 

# class `ColorFactory` 

this class stores all Factories, initializes a New [Color](#class_color) object when required, returns what kind of operation can be done with a specific color rappresentation and returs the result using the permitted operations

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `ColorModel` 

```
class ColorModel
  : public Model
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`ColorModel`](#class_color_model_1ae5658c9698e4f3ffbe880249939f4282)`(const `[`Model`](#class_model)` * previous)` | Model::Model inizialize the [ColorModel](#class_color_model) and assign the older [ColorModel](#class_color_model) if exists.
`public  `[`~ColorModel`](#class_color_model_1ace1f2efdd5fd223daa7e9cf002556a04)`()` | 
`public virtual QVector< QString > `[`availableOperations`](#class_color_model_1aab6a725338946ecec218220f5606be45)`() const` | [ColorModel::availableOperations](#class_color_model_1aab6a725338946ecec218220f5606be45).
`public virtual QVector< QString > `[`allAvailableTypes`](#class_color_model_1ac1788de4bf589070a2e915ff43d073ad)`() const` | [ColorModel::allAvailableTypes](#class_color_model_1ac1788de4bf589070a2e915ff43d073ad).
`{slot} public void `[`setLeftType`](#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37)`(QString type)` | [ColorModel::setLeftType](#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37).
`{slot} public void `[`setLeftValues`](#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5)`(QVector< QString > values)` | [ColorModel::setLeftValues](#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5).
`{slot} public void `[`setRightType`](#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38)`(QString type)` | [ColorModel::setRightType](#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38).
`{slot} public void `[`setRightValues`](#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6)`(QVector< QString > values)` | [ColorModel::setRightValues](#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6).
`{slot} public void `[`setLastResultAsLeftOperand`](#class_color_model_1ad1540733700acad1d488dd91c9473f0f)`()` | 
`{slot} public void `[`setOp`](#class_color_model_1ad51072410fbe8572066b3a53ca85a289)`(QString eOperation)` | [ColorModel::setOp](#class_color_model_1ad51072410fbe8572066b3a53ca85a289).
`{slot} public void `[`execute`](#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640)`()` | [ColorModel::execute](#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640) execute the operation.
`{slot} public void `[`getResult`](#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d)`()` | [ColorModel::getResult](#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d) set up result object.
`{slot} public QVector< QString > `[`getHistory`](#class_color_model_1ae6d45b8310f0eb35f9d92de11a786261)`()` | [ColorModel::getHistory](#class_color_model_1ae6d45b8310f0eb35f9d92de11a786261).

## Members

#### `public  `[`ColorModel`](#class_color_model_1ae5658c9698e4f3ffbe880249939f4282)`(const `[`Model`](#class_model)` * previous)` 

Model::Model inizialize the [ColorModel](#class_color_model) and assign the older [ColorModel](#class_color_model) if exists.

#### Parameters
* `previous`

#### `public  `[`~ColorModel`](#class_color_model_1ace1f2efdd5fd223daa7e9cf002556a04)`()` 

#### `public virtual QVector< QString > `[`availableOperations`](#class_color_model_1aab6a725338946ecec218220f5606be45)`() const` 

[ColorModel::availableOperations](#class_color_model_1aab6a725338946ecec218220f5606be45).

#### Returns
QVector<QString> that contains all the operation that are available

#### `public virtual QVector< QString > `[`allAvailableTypes`](#class_color_model_1ac1788de4bf589070a2e915ff43d073ad)`() const` 

[ColorModel::allAvailableTypes](#class_color_model_1ac1788de4bf589070a2e915ff43d073ad).

#### Returns
QVector<QString> that contains all permitted types

#### `{slot} public void `[`setLeftType`](#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37)`(QString type)` 

[ColorModel::setLeftType](#class_color_model_1a747a1c9db1fb6f8eecf3a89adf5d5d37).

#### Parameters
* `type` setup the left operand type

#### `{slot} public void `[`setLeftValues`](#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5)`(QVector< QString > values)` 

[ColorModel::setLeftValues](#class_color_model_1a7954f6e500e4a2a7d9aa5813f5e288d5).

#### Parameters
* `values` set values to the left operand

#### `{slot} public void `[`setRightType`](#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38)`(QString type)` 

[ColorModel::setRightType](#class_color_model_1acad4c21bc8bcede62c821f6e87a44e38).

#### Parameters
* `type` set the right operand type

#### `{slot} public void `[`setRightValues`](#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6)`(QVector< QString > values)` 

[ColorModel::setRightValues](#class_color_model_1a07658db30b08f31f8f8190b6f4ed98d6).

#### Parameters
* `values` set values to the right operand

#### `{slot} public void `[`setLastResultAsLeftOperand`](#class_color_model_1ad1540733700acad1d488dd91c9473f0f)`()` 

#### `{slot} public void `[`setOp`](#class_color_model_1ad51072410fbe8572066b3a53ca85a289)`(QString eOperation)` 

[ColorModel::setOp](#class_color_model_1ad51072410fbe8572066b3a53ca85a289).

#### Parameters
* `eOperation` set up the operation that will be executed

#### `{slot} public void `[`execute`](#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640)`()` 

[ColorModel::execute](#class_color_model_1a3fcb0b558eb03b628a898f845dcb8640) execute the operation.

#### `{slot} public void `[`getResult`](#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d)`()` 

[ColorModel::getResult](#class_color_model_1ab64c059ce583856ec5dd9e35244ac92d) set up result object.

#### `{slot} public QVector< QString > `[`getHistory`](#class_color_model_1ae6d45b8310f0eb35f9d92de11a786261)`()` 

[ColorModel::getHistory](#class_color_model_1ae6d45b8310f0eb35f9d92de11a786261).

#### Returns
QVector<QString> with the history of the operation that has been done

# class `ConsoleView` 

```
class ConsoleView
  : public View
```  

[ConsoleView](#class_console_view) exestends the [View](#class_view) class and provides an interface in terminal line.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`ConsoleView`](#class_console_view_1ae8a2079a84bc7b7e2b8a68f927cae911)`(`[`View`](#class_view)` * parent)` | 
`public  `[`ConsoleView`](#class_console_view_1a42ca0ca912c42d743a64f7e3a80b6f26)`(const `[`ConsoleView`](#class_console_view)` & console)` | 
`public  `[`~ConsoleView`](#class_console_view_1ac1176e89fc21883badc833e6167726d6)`() = default` | 
`{slot} public void `[`setAvailableOperations`](#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec)`(const QVector< QString > operations)` | [ConsoleView::setAvailableOperations](#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec).
`{slot} public void `[`setPermittedOperations`](#class_console_view_1a17864810f831eb58d8be275a2eaa461d)`(const QVector< QString > operations)` | [ConsoleView::setPermittedOperations](#class_console_view_1a17864810f831eb58d8be275a2eaa461d).
`{slot} public void `[`setLeftTypes`](#class_console_view_1a7dcc84dc917fb81babae471315e9cefd)`(const QVector< QString > types)` | [ConsoleView::setLeftTypes](#class_console_view_1a7dcc84dc917fb81babae471315e9cefd).
`{slot} public void `[`setLeftFields`](#class_console_view_1a5cd7ddd082659cb0f8e42360eb2d0961)`(const int & fields)` | [ConsoleView::setLeftFields](#class_console_view_1a5cd7ddd082659cb0f8e42360eb2d0961).
`{slot} public void `[`setRightTypes`](#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4)`(const QVector< QString > types)` | [ConsoleView::setRightTypes](#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4).
`{slot} public void `[`setRightFields`](#class_console_view_1aa909d516e7d44af466fb1c6edfe7644d)`(const int & fields)` | [ConsoleView::setRightFields](#class_console_view_1aa909d516e7d44af466fb1c6edfe7644d).
`{slot} public void `[`setResult`](#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37)`(const QVector< QString > result)` | [ConsoleView::setResult](#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37).
`{slot} public void `[`setResultFields`](#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3)`(const int & fields)` | [ConsoleView::setResultFields](#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3).
`{slot} public void `[`update`](#class_console_view_1a4341841ffd341af9fd439ca9e7a7bbd2)`()` | [ConsoleView::update](#class_console_view_1a4341841ffd341af9fd439ca9e7a7bbd2) useless.
`{slot} public void `[`show`](#class_console_view_1a64444203b69213adbe63da93d3d03cb4)`()` | [ConsoleView::show](#class_console_view_1a64444203b69213adbe63da93d3d03cb4) inizialize the view inside the terminal.

## Members

#### `public inline  `[`ConsoleView`](#class_console_view_1ae8a2079a84bc7b7e2b8a68f927cae911)`(`[`View`](#class_view)` * parent)` 

#### `public  `[`ConsoleView`](#class_console_view_1a42ca0ca912c42d743a64f7e3a80b6f26)`(const `[`ConsoleView`](#class_console_view)` & console)` 

#### `public  `[`~ConsoleView`](#class_console_view_1ac1176e89fc21883badc833e6167726d6)`() = default` 

#### `{slot} public void `[`setAvailableOperations`](#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec)`(const QVector< QString > operations)` 

[ConsoleView::setAvailableOperations](#class_console_view_1a6d88d3e3957fb1cdea6e076770fffdec).

#### Parameters
* `opt` sets up all operations that are available not really required

#### `{slot} public void `[`setPermittedOperations`](#class_console_view_1a17864810f831eb58d8be275a2eaa461d)`(const QVector< QString > operations)` 

[ConsoleView::setPermittedOperations](#class_console_view_1a17864810f831eb58d8be275a2eaa461d).

#### Parameters
* `opt` sets up all operations that the user can execute

#### `{slot} public void `[`setLeftTypes`](#class_console_view_1a7dcc84dc917fb81babae471315e9cefd)`(const QVector< QString > types)` 

[ConsoleView::setLeftTypes](#class_console_view_1a7dcc84dc917fb81babae471315e9cefd).

#### Parameters
* `types` sets up l_types variable

#### `{slot} public void `[`setLeftFields`](#class_console_view_1a5cd7ddd082659cb0f8e42360eb2d0961)`(const int & fields)` 

[ConsoleView::setLeftFields](#class_console_view_1a5cd7ddd082659cb0f8e42360eb2d0961).

#### Parameters
* `fields` sets up l_size variable

#### `{slot} public void `[`setRightTypes`](#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4)`(const QVector< QString > types)` 

[ConsoleView::setRightTypes](#class_console_view_1a96f03ac06e40ae1d45601ac9f11863c4).

#### Parameters
* `types` sets up r_types variable

#### `{slot} public void `[`setRightFields`](#class_console_view_1aa909d516e7d44af466fb1c6edfe7644d)`(const int & fields)` 

[ConsoleView::setRightFields](#class_console_view_1aa909d516e7d44af466fb1c6edfe7644d).

#### Parameters
* `fields` sets up r_size variable

#### `{slot} public void `[`setResult`](#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37)`(const QVector< QString > result)` 

[ConsoleView::setResult](#class_console_view_1a0b43a9e8d693b227fcd3a00b7a384e37).

#### Parameters
* `result` sets up local_result variable

#### `{slot} public void `[`setResultFields`](#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3)`(const int & fields)` 

[ConsoleView::setResultFields](#class_console_view_1afeb190605800a7ce7b8b3224a32b15a3).

#### Parameters
* `fields` does nothing because the resultFields are the same as left operand

#### `{slot} public void `[`update`](#class_console_view_1a4341841ffd341af9fd439ca9e7a7bbd2)`()` 

[ConsoleView::update](#class_console_view_1a4341841ffd341af9fd439ca9e7a7bbd2) useless.

#### `{slot} public void `[`show`](#class_console_view_1a64444203b69213adbe63da93d3d03cb4)`()` 

[ConsoleView::show](#class_console_view_1a64444203b69213adbe63da93d3d03cb4) inizialize the view inside the terminal.

# class `Controller` 

```
class Controller
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Controller`](#class_controller_1a7984f40669752a82c87e067bec6c3751)`(`[`Model`](#class_model)` * f_model,`[`View`](#class_view)` * f_view)` | 
`public void `[`setUp`](#class_controller_1ac5b5525e1a9fc6914657dd8d943a0928)`()` | 
`public void `[`connect`](#class_controller_1afe28638e4396e7b8415cbe5d05964ad2)`()` | 
`{slot} public void `[`newModel`](#class_controller_1acdb404d69222d41c55b4358ef844cd8f)`()` | 
`{slot} public void `[`oldResult`](#class_controller_1acde8ea3614a810d9527bf6daa7678e8b)`()` | 

## Members

#### `public  `[`Controller`](#class_controller_1a7984f40669752a82c87e067bec6c3751)`(`[`Model`](#class_model)` * f_model,`[`View`](#class_view)` * f_view)` 

#### `public void `[`setUp`](#class_controller_1ac5b5525e1a9fc6914657dd8d943a0928)`()` 

#### `public void `[`connect`](#class_controller_1afe28638e4396e7b8415cbe5d05964ad2)`()` 

#### `{slot} public void `[`newModel`](#class_controller_1acdb404d69222d41c55b4358ef844cd8f)`()` 

#### `{slot} public void `[`oldResult`](#class_controller_1acde8ea3614a810d9527bf6daa7678e8b)`()` 

# class `CYMK` 

```
class CYMK
  : public CIExyz
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`CYMK`](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d)`(unsigned int c,unsigned int y,unsigned int m,unsigned int k)` | 
`public  `[`CYMK`](#class_c_y_m_k_1ab524ef2e847938b2efff28886387ec51)`(const `[`Color`](#class_color)` * from)` | 
`public  `[`CYMK`](#class_c_y_m_k_1a4bccfb3b46229aa82827bd6988efaa8c)`(const `[`CYMK`](#class_c_y_m_k)` & from)` | 
`public virtual QString `[`getRappresentation`](#class_c_y_m_k_1ad4f93bcaf6209ed5479b68618e0dcc35)`() const` | [CIExyz::getRappresentation](#class_c_i_exyz_1a116a1e50a9399db86333f02a8961c2d1).
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_c_y_m_k_1a397c0109e76ff6cc331b49e4b73623ef)`() const` | [CIExyz::negate](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_c_y_m_k_1adeb4691eafbb53e15538a3d829f59a14)`(const `[`Color`](#class_color)` * c) const` | [CIExyz::mix](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8).
`public `[`Color`](#class_color)` * `[`getCIE`](#class_c_y_m_k_1ad92097bbc8fa491be286a76588285d1e)`(unsigned int c,unsigned int y,unsigned int m,unsigned int k) const` | 
`public virtual QVector< double > `[`getComponents`](#class_c_y_m_k_1a46e1058b0332d73710efa5d9f4644ba2)`() const` | CIExyz::getComponent.
`public virtual int `[`getNumberOfComponets`](#class_c_y_m_k_1ab3f005a1cc28f715192ad4fc90ded6b8)`() const` | [CIExyz::getNumberOfComponets](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e).
`public virtual void `[`setComponents`](#class_c_y_m_k_1a897a2a1030cfd10dc16d5e2de825b45e)`(QVector< double > componets)` | [CIExyz::setComponents](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84) set the components inside the object.

## Members

#### `public  `[`CYMK`](#class_c_y_m_k_1a1aa6a0953837818a2b298476cab9388d)`(unsigned int c,unsigned int y,unsigned int m,unsigned int k)` 

#### `public  `[`CYMK`](#class_c_y_m_k_1ab524ef2e847938b2efff28886387ec51)`(const `[`Color`](#class_color)` * from)` 

#### `public  `[`CYMK`](#class_c_y_m_k_1a4bccfb3b46229aa82827bd6988efaa8c)`(const `[`CYMK`](#class_c_y_m_k)` & from)` 

#### `public virtual QString `[`getRappresentation`](#class_c_y_m_k_1ad4f93bcaf6209ed5479b68618e0dcc35)`() const` 

[CIExyz::getRappresentation](#class_c_i_exyz_1a116a1e50a9399db86333f02a8961c2d1).

#### Returns
QString that contains the meaning of the values contained in [getComponents()](#class_c_y_m_k_1a46e1058b0332d73710efa5d9f4644ba2)

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_c_y_m_k_1a397c0109e76ff6cc331b49e4b73623ef)`() const` 

[CIExyz::negate](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94).

#### Returns
[Color](#class_color) pointer with a new color with the complementar values

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_c_y_m_k_1adeb4691eafbb53e15538a3d829f59a14)`(const `[`Color`](#class_color)` * c) const` 

[CIExyz::mix](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8).

#### Parameters
* `c` 

#### Returns
[Color](#class_color) pointer with a new Object color mixed

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_c_y_m_k_1ad92097bbc8fa491be286a76588285d1e)`(unsigned int c,unsigned int y,unsigned int m,unsigned int k) const` 

#### `public virtual QVector< double > `[`getComponents`](#class_c_y_m_k_1a46e1058b0332d73710efa5d9f4644ba2)`() const` 

CIExyz::getComponent.

#### Returns
QVector<double> with the x y z component of the color in CIE XYZ

#### `public virtual int `[`getNumberOfComponets`](#class_c_y_m_k_1ab3f005a1cc28f715192ad4fc90ded6b8)`() const` 

[CIExyz::getNumberOfComponets](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e).

#### Returns
int componets number

#### `public virtual void `[`setComponents`](#class_c_y_m_k_1a897a2a1030cfd10dc16d5e2de825b45e)`(QVector< double > componets)` 

[CIExyz::setComponents](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84) set the components inside the object.

#### Parameters
* `componets`

# class `Factory` 

```
class Factory
  : public GenericFactory
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Factory`](#class_factory_1aa9715c3cc1d43c571191d8bbc1203633)`()` | 
`public inline virtual `[`Color`](#class_color)` * `[`getNewColor`](#class_factory_1a6c7dcfb9ba1de182fcd6b2e0990d02f3)`() const` | 

## Members

#### `public inline  `[`Factory`](#class_factory_1aa9715c3cc1d43c571191d8bbc1203633)`()` 

#### `public inline virtual `[`Color`](#class_color)` * `[`getNewColor`](#class_factory_1a6c7dcfb9ba1de182fcd6b2e0990d02f3)`() const` 

# class `Factory< T >` 

this class extends [GenericFactory](#class_generic_factory) and implements getNewColor() inizializes the map allColorFactories in [ColorFactory](#class_color_factory) and makes available to [ColorFactory](#class_color_factory) a constructor for the new color requested

this class is uses as base object to recall a Factory<t> getNewColor

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `GenericFactory` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public `[`Color`](#class_color)` * `[`getNewColor`](#class_generic_factory_1a1e4a2993cb1684a24ed3edfb06efdaed)`() const` | 

## Members

#### `public `[`Color`](#class_color)` * `[`getNewColor`](#class_generic_factory_1a1e4a2993cb1684a24ed3edfb06efdaed)`() const` 

# class `HSL` 

```
class HSL
  : public CIExyz
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`HSL`](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182)`(double h,double s,double l)` | 
`public  `[`HSL`](#class_h_s_l_1ae737a28ec6a67bba89090c9a63c5cc21)`(const `[`Color`](#class_color)` * from)` | 
`public  `[`HSL`](#class_h_s_l_1a165c0123fc7294e7ccdc53fc11c57154)`(const `[`HSL`](#class_h_s_l)` & from)` | 
`public virtual QString `[`getRappresentation`](#class_h_s_l_1a2a6b1b0b5176ad741614ed15f05a9fd0)`() const` | [CIExyz::getRappresentation](#class_c_i_exyz_1a116a1e50a9399db86333f02a8961c2d1).
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_h_s_l_1af681f885d11220b0588e8f969aa95e32)`() const` | [CIExyz::negate](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_h_s_l_1a08bcec2ca6961b7c6431d92a625c30a7)`(const `[`Color`](#class_color)` * c) const` | [CIExyz::mix](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8).
`public `[`Color`](#class_color)` * `[`getCIE`](#class_h_s_l_1ad755c96eff0cc73dea69c007d745dd4e)`(double h,double s,double l) const` | 
`public virtual QVector< double > `[`getComponents`](#class_h_s_l_1a2de2eb4fa5c9ffcea894f7c6591cb335)`() const` | CIExyz::getComponent.
`public virtual void `[`setComponents`](#class_h_s_l_1a101be14729707abca388680610e2fe86)`(QVector< double > componets)` | [CIExyz::setComponents](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84) set the components inside the object.
`public virtual int `[`getNumberOfComponets`](#class_h_s_l_1a6e582f5779c1b5f84abe8bb182a868d0)`() const` | [CIExyz::getNumberOfComponets](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e).

## Members

#### `public  `[`HSL`](#class_h_s_l_1af90e79ad88ecb7944c313330d4bde182)`(double h,double s,double l)` 

#### `public  `[`HSL`](#class_h_s_l_1ae737a28ec6a67bba89090c9a63c5cc21)`(const `[`Color`](#class_color)` * from)` 

#### `public  `[`HSL`](#class_h_s_l_1a165c0123fc7294e7ccdc53fc11c57154)`(const `[`HSL`](#class_h_s_l)` & from)` 

#### `public virtual QString `[`getRappresentation`](#class_h_s_l_1a2a6b1b0b5176ad741614ed15f05a9fd0)`() const` 

[CIExyz::getRappresentation](#class_c_i_exyz_1a116a1e50a9399db86333f02a8961c2d1).

#### Returns
QString that contains the meaning of the values contained in [getComponents()](#class_h_s_l_1a2de2eb4fa5c9ffcea894f7c6591cb335)

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_h_s_l_1af681f885d11220b0588e8f969aa95e32)`() const` 

[CIExyz::negate](#class_c_i_exyz_1a4a454df6cbb71f3fcfd2d1ea9d500d94).

#### Returns
[Color](#class_color) pointer with a new color with the complementar values

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_h_s_l_1a08bcec2ca6961b7c6431d92a625c30a7)`(const `[`Color`](#class_color)` * c) const` 

[CIExyz::mix](#class_c_i_exyz_1af8eeb48ade44beea43d023b36d263fc8).

#### Parameters
* `c` 

#### Returns
[Color](#class_color) pointer with a new Object color mixed

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_h_s_l_1ad755c96eff0cc73dea69c007d745dd4e)`(double h,double s,double l) const` 

#### `public virtual QVector< double > `[`getComponents`](#class_h_s_l_1a2de2eb4fa5c9ffcea894f7c6591cb335)`() const` 

CIExyz::getComponent.

#### Returns
QVector<double> with the x y z component of the color in CIE XYZ

#### `public virtual void `[`setComponents`](#class_h_s_l_1a101be14729707abca388680610e2fe86)`(QVector< double > componets)` 

[CIExyz::setComponents](#class_c_i_exyz_1a11468574f91d2cb1356f0cde56429b84) set the components inside the object.

#### Parameters
* `componets`

#### `public virtual int `[`getNumberOfComponets`](#class_h_s_l_1a6e582f5779c1b5f84abe8bb182a868d0)`() const` 

[CIExyz::getNumberOfComponets](#class_c_i_exyz_1af168733bb1bca36a7ae5d75c67de046e).

#### Returns
int componets number

# class `IllegalColorException` 

```
class IllegalColorException
  : public runtime_error
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`IllegalColorException`](#class_illegal_color_exception_1a2d06f0597577dae21d50835a9e95e531)`(std::string e)` | 

## Members

#### `public inline  `[`IllegalColorException`](#class_illegal_color_exception_1a2d06f0597577dae21d50835a9e95e531)`(std::string e)` 

# class `MainWindow` 

```
class MainWindow
  : public View
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`MainWindow`](#class_main_window_1a996c5a2b6f77944776856f08ec30858d)`(QWidget * parent)` | 
`public  `[`~MainWindow`](#class_main_window_1ae98d00a93bc118200eeef9f9bba1dba7)`()` | 
`{slot} public void `[`setLeftTypes`](#class_main_window_1ae065551040ada6411fc1fb4f3887dd3b)`(const QVector< QString > types)` | 
`{slot} public void `[`setRightTypes`](#class_main_window_1aca464c6893a9551372c043cb3bf7bf56)`(const QVector< QString > types)` | 
`{slot} public void `[`setLeftFields`](#class_main_window_1a84091605f2eed872554140d157f25eae)`(const int & fields)` | 
`{slot} public void `[`setRightFields`](#class_main_window_1aaf4ac2f7688c9d93fc4da6c8d8e9a31a)`(const int & fields)` | 
`{slot} public void `[`setResultFields`](#class_main_window_1ae00d4afec436d34430e43dcc6742b875)`(const int & fields)` | 
`{slot} public void `[`setAvailableOperations`](#class_main_window_1a282ffcc1cb28b83d4f8fe510f6b2e42e)`(const QVector< QString > operations)` | 
`{slot} public void `[`setPermittedOperations`](#class_main_window_1a86f711960ec362153b5d2ef6667c6c0c)`(const QVector< QString > operations)` | 
`{slot} public void `[`setResult`](#class_main_window_1a04fa84f042da5f258d1dc09803667bbf)`(const QVector< QString > result)` | 
`{slot} public void `[`ansIsSet`](#class_main_window_1ada34581acaaeff9260e0f76ced8e8bb7)`(const QVector< QString > values)` | 
`{slot} public void `[`setNumPad`](#class_main_window_1aa16f2c84e4ddda0e0544e1e189b3bc62)`()` | 
`{slot} public void `[`show`](#class_main_window_1ae3d7a4598609a86e8bd317c0d85c4495)`()` | 
`{slot} public void `[`update`](#class_main_window_1a128f71880d4b9683149023fc46fcc9f8)`()` | 

## Members

#### `public  `[`MainWindow`](#class_main_window_1a996c5a2b6f77944776856f08ec30858d)`(QWidget * parent)` 

#### `public  `[`~MainWindow`](#class_main_window_1ae98d00a93bc118200eeef9f9bba1dba7)`()` 

#### `{slot} public void `[`setLeftTypes`](#class_main_window_1ae065551040ada6411fc1fb4f3887dd3b)`(const QVector< QString > types)` 

#### `{slot} public void `[`setRightTypes`](#class_main_window_1aca464c6893a9551372c043cb3bf7bf56)`(const QVector< QString > types)` 

#### `{slot} public void `[`setLeftFields`](#class_main_window_1a84091605f2eed872554140d157f25eae)`(const int & fields)` 

#### `{slot} public void `[`setRightFields`](#class_main_window_1aaf4ac2f7688c9d93fc4da6c8d8e9a31a)`(const int & fields)` 

#### `{slot} public void `[`setResultFields`](#class_main_window_1ae00d4afec436d34430e43dcc6742b875)`(const int & fields)` 

#### `{slot} public void `[`setAvailableOperations`](#class_main_window_1a282ffcc1cb28b83d4f8fe510f6b2e42e)`(const QVector< QString > operations)` 

#### `{slot} public void `[`setPermittedOperations`](#class_main_window_1a86f711960ec362153b5d2ef6667c6c0c)`(const QVector< QString > operations)` 

#### `{slot} public void `[`setResult`](#class_main_window_1a04fa84f042da5f258d1dc09803667bbf)`(const QVector< QString > result)` 

#### `{slot} public void `[`ansIsSet`](#class_main_window_1ada34581acaaeff9260e0f76ced8e8bb7)`(const QVector< QString > values)` 

#### `{slot} public void `[`setNumPad`](#class_main_window_1aa16f2c84e4ddda0e0544e1e189b3bc62)`()` 

#### `{slot} public void `[`show`](#class_main_window_1ae3d7a4598609a86e8bd317c0d85c4495)`()` 

#### `{slot} public void `[`update`](#class_main_window_1a128f71880d4b9683149023fc46fcc9f8)`()` 

# class `Model` 

```
class Model
  : public QObject
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public QVector< QString > `[`availableOperations`](#class_model_1a2e34231c9285a6c0a3e3f0c5cd4d51aa)`() const` | 
`public QVector< QString > `[`allAvailableTypes`](#class_model_1ad8efaa1708d2179e4a8e1474cae2df1d)`() const` | 
`{signal} public void `[`permittedOperations`](#class_model_1a636cd0b310ee32bd0d7f4a158cb56b6d)`(QVector< QString > operations)` | 
`{signal} public void `[`leftSize`](#class_model_1a23d5415b10db5620929dbdc15b0512b7)`(int size)` | 
`{signal} public void `[`rightSize`](#class_model_1a093a4b575a13b03409a32872b470172e)`(int size)` | 
`{signal} public void `[`rightTypes`](#class_model_1a4019e969fe2996f955d07852f10693dd)`(QVector< QString > permittedTypes)` | 
`{signal} public void `[`resultReady`](#class_model_1ae794cf24374d3c78f1b49731d096a077)`(QVector< QString > result)` | 
`{signal} public void `[`update`](#class_model_1a8976f84f757eb3cd68b2aa7eeb5a345f)`()` | 
`{signal} public void `[`history`](#class_model_1a9f9602f0d662455b5d25ad45d685c4fe)`(QVector< QString > olds)` | 
`{slot} public void `[`setLeftType`](#class_model_1a61d4e70e34d66e77bd508016be6e9637)`(QString type)` | 
`{slot} public void `[`setLeftValues`](#class_model_1ac3c03d44daacd6ad697481c576596592)`(QVector< QString > values)` | 
`{slot} public void `[`setRightType`](#class_model_1a967c3fccc96188c8087b1062045af857)`(QString type)` | 
`{slot} public void `[`setRightValues`](#class_model_1aed3bb530900e322630e2e39eb780991f)`(QVector< QString > values)` | 
`{slot} public void `[`setLastResultAsLeftOperand`](#class_model_1aef0ff93944d27829d3de87d5bf4fd6f6)`()` | 
`{slot} public void `[`setOp`](#class_model_1ac58ba62771e20dd87da313b7e399df69)`(QString eOperation)` | 
`{slot} public void `[`execute`](#class_model_1a95509d1e8dd8acff059eec72ac75f496)`()` | 
`{slot} public void `[`getResult`](#class_model_1a00ecb7bd9d19ba145a1ec536539fe08f)`()` | 
`{slot} public QVector< QString > `[`getHistory`](#class_model_1afcb2772854bc97879f53e75e4b8bcb45)`()` | 

## Members

#### `public QVector< QString > `[`availableOperations`](#class_model_1a2e34231c9285a6c0a3e3f0c5cd4d51aa)`() const` 

#### `public QVector< QString > `[`allAvailableTypes`](#class_model_1ad8efaa1708d2179e4a8e1474cae2df1d)`() const` 

#### `{signal} public void `[`permittedOperations`](#class_model_1a636cd0b310ee32bd0d7f4a158cb56b6d)`(QVector< QString > operations)` 

#### `{signal} public void `[`leftSize`](#class_model_1a23d5415b10db5620929dbdc15b0512b7)`(int size)` 

#### `{signal} public void `[`rightSize`](#class_model_1a093a4b575a13b03409a32872b470172e)`(int size)` 

#### `{signal} public void `[`rightTypes`](#class_model_1a4019e969fe2996f955d07852f10693dd)`(QVector< QString > permittedTypes)` 

#### `{signal} public void `[`resultReady`](#class_model_1ae794cf24374d3c78f1b49731d096a077)`(QVector< QString > result)` 

#### `{signal} public void `[`update`](#class_model_1a8976f84f757eb3cd68b2aa7eeb5a345f)`()` 

#### `{signal} public void `[`history`](#class_model_1a9f9602f0d662455b5d25ad45d685c4fe)`(QVector< QString > olds)` 

#### `{slot} public void `[`setLeftType`](#class_model_1a61d4e70e34d66e77bd508016be6e9637)`(QString type)` 

#### `{slot} public void `[`setLeftValues`](#class_model_1ac3c03d44daacd6ad697481c576596592)`(QVector< QString > values)` 

#### `{slot} public void `[`setRightType`](#class_model_1a967c3fccc96188c8087b1062045af857)`(QString type)` 

#### `{slot} public void `[`setRightValues`](#class_model_1aed3bb530900e322630e2e39eb780991f)`(QVector< QString > values)` 

#### `{slot} public void `[`setLastResultAsLeftOperand`](#class_model_1aef0ff93944d27829d3de87d5bf4fd6f6)`()` 

#### `{slot} public void `[`setOp`](#class_model_1ac58ba62771e20dd87da313b7e399df69)`(QString eOperation)` 

#### `{slot} public void `[`execute`](#class_model_1a95509d1e8dd8acff059eec72ac75f496)`()` 

#### `{slot} public void `[`getResult`](#class_model_1a00ecb7bd9d19ba145a1ec536539fe08f)`()` 

#### `{slot} public QVector< QString > `[`getHistory`](#class_model_1afcb2772854bc97879f53e75e4b8bcb45)`()` 

# class `RGB` 

```
class RGB
  : public CIExyz
```  

this class uses the as base class [CIExyz](#class_c_i_exyz) and stores a color in [RGB](#class_r_g_b) rappresentation

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
`public virtual QString `[`getRappresentation`](#class_r_g_b_1a745d03e1bf66224b0ce39ac9fa92aa6a)`() const` | [RGB::getRappresentation](#class_r_g_b_1a745d03e1bf66224b0ce39ac9fa92aa6a) returns the meaning of the values contained in [getComponents()](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769)
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69)`() const` | [RGB::negate](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9)`(const `[`Color`](#class_color)` * c) const` | [RGB::mix](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9).
`public virtual `[`Color`](#class_color)` * `[`operator/`](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80)`(const int & div) const` | [RGB::operator /](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80) new [RGB](#class_r_g_b) object with value divided.
`public virtual QVector< QString > `[`availableOperations`](#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4)`() const` | [RGB::availableOperations](#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4) returns all the operation that has been implemented.
`public virtual QVector< double > `[`getComponents`](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769)`() const` | RGB::getComponent returns component in [RGB](#class_r_g_b) class;.
`public virtual int `[`getNumberOfComponets`](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345)`() const` | [RGB::getNumberOfComponets](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345).
`public `[`CIExyz`](#class_c_i_exyz)` * `[`getCIE`](#class_r_g_b_1a153f315167dfd89944c625d43b307b43)`(int t_r,int t_g,int t_b) const` | [RGB::getCIE](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24) converts [RGB](#class_r_g_b) value to [CIExyz](#class_c_i_exyz).

## Members

#### `public  `[`RGB`](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001)`(int r,int g,int b)` 

[RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).

#### Parameters
* `int` t_r 

* `int` t_g 

* `int` t_b

uses the local function getCIE(int t_r, int t_g, int t_b) to inizialize the parent object and set the local array values to rgb in input order

#### `public  `[`RGB`](#class_r_g_b_1a4b69fccf264945ab5d708738824bd93a)`(const `[`RGB`](#class_r_g_b)` & c)` 

[RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).

#### Parameters
* `RGB&` t_c Constructor that takes a [RGB](#class_r_g_b) pointer and clones the object

#### `public  `[`RGB`](#class_r_g_b_1a9caf6caec9c6e67896b24ba3a1715342)`(const `[`RGB`](#class_r_g_b)` * c)` 

[RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).

#### Parameters
* `RGB*` t_c

#### `public  `[`RGB`](#class_r_g_b_1acabd7e004d54445c5e87f27fcd06ad33)`(const `[`Color`](#class_color)` * c)` 

[RGB::RGB](#class_r_g_b_1ab48fc0751f6432ff993b31119f289001).

#### Parameters
* `Color*` t_c Constructor for [RGB](#class_r_g_b) that get a [Color](#class_color) pointer And inzialize parent objcet with a clone of [CIExyz](#class_c_i_exyz) rappresentation

#### `public  `[`~RGB`](#class_r_g_b_1a2f89f461b43bc3036dafbc899e8204f5)`() = default` 

#### `public virtual `[`Color`](#class_color)` * `[`getCIE`](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24)`() const` 

[RGB::getCIE](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24).

#### Returns
[CIExyz](#class_c_i_exyz)

#### `public virtual void `[`setComponents`](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36)`(QVector< double > componets)` 

[RGB::setComponents](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36) set the components inside the object.

#### Parameters
* `componets`

#### `public virtual QString `[`getRappresentation`](#class_r_g_b_1a745d03e1bf66224b0ce39ac9fa92aa6a)`() const` 

[RGB::getRappresentation](#class_r_g_b_1a745d03e1bf66224b0ce39ac9fa92aa6a) returns the meaning of the values contained in [getComponents()](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769)

#### Returns
QString

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69)`() const` 

[RGB::negate](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69).

#### Returns
return a new [Color](#class_color) object with a new complementary color

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9)`(const `[`Color`](#class_color)` * c) const` 

[RGB::mix](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9).

#### Parameters
* `Color*` t_c 

#### Returns
a new [Color](#class_color) object with the mixed Colors

#### `public virtual `[`Color`](#class_color)` * `[`operator/`](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80)`(const int & div) const` 

[RGB::operator /](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80) new [RGB](#class_r_g_b) object with value divided.

#### Parameters
* `int` div 

#### Returns
[RGB](#class_r_g_b)

#### `public virtual QVector< QString > `[`availableOperations`](#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4)`() const` 

[RGB::availableOperations](#class_r_g_b_1a6cde5a9d00036c76fef2dd51ca8256a4) returns all the operation that has been implemented.

#### Returns
QVector<QString>

#### `public virtual QVector< double > `[`getComponents`](#class_r_g_b_1ad085d3bd654d874ea2e5739a5c216769)`() const` 

RGB::getComponent returns component in [RGB](#class_r_g_b) class;.

#### Returns
QVector<double>

#### `public virtual int `[`getNumberOfComponets`](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345)`() const` 

[RGB::getNumberOfComponets](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345).

#### Returns
int

#### `public `[`CIExyz`](#class_c_i_exyz)` * `[`getCIE`](#class_r_g_b_1a153f315167dfd89944c625d43b307b43)`(int t_r,int t_g,int t_b) const` 

[RGB::getCIE](#class_r_g_b_1ac4b085d5587c664f7f9ceae1eb857d24) converts [RGB](#class_r_g_b) value to [CIExyz](#class_c_i_exyz).

#### Parameters
* `int` t_r 

* `int` t_g 

* `int` t_b 

#### Returns
CIExyz*

# class `View` 

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
`{signal} public void `[`operationIsSet`](#class_view_1af4cf1863986a0fac18d6da46c97329de)`(QString opt)` | 
`{signal} public void `[`getResult`](#class_view_1ac05f93e75953488aa1a5a3f813603032)`()` | 
`{signal} public void `[`reset`](#class_view_1a84eea48d2036da09640369d7997d957b)`()` | 
`{signal} public void `[`lastOperation`](#class_view_1ae52f108d479e4d38f13ffc1ad97f7d5c)`()` | 
`{signal} public void `[`done`](#class_view_1af0a5104e717bfe94ae35a1dfd9d5e183)`()` | 
`{slot} public void `[`setAvailableOperations`](#class_view_1a203ab36b8546f1d9dc630bd7c0536e67)`(const QVector< QString > operations)` | 
`{slot} public void `[`setPermittedOperations`](#class_view_1a5b3c08e11f2aece6c28c9b36e41ae35a)`(const QVector< QString > operations)` | 
`{slot} public void `[`setLeftTypes`](#class_view_1a80c90f9167a8bc834d8c2f25be9e5f0d)`(const QVector< QString > types)` | 
`{slot} public void `[`setLeftFields`](#class_view_1aa5db4d4ea2851a9ff4e923e38d219bec)`(const int & fields)` | 
`{slot} public void `[`setRightTypes`](#class_view_1a26bb1996d32f29476ba3c0b5c01561fc)`(const QVector< QString > types)` | 
`{slot} public void `[`setRightFields`](#class_view_1a63b329facfe2280261b7f01b582eadf9)`(const int & fields)` | 
`{slot} public void `[`setResult`](#class_view_1a2d78db2bd23a6dd80bfeae64f4c3fdd3)`(const QVector< QString > result)` | 
`{slot} public void `[`setResultFields`](#class_view_1ad3f5b700bd33a72bebc6efdbad2d17eb)`(const int & fields)` | 
`{slot} public void `[`update`](#class_view_1a8caf26d67197c101c37da5c9cddfb534)`()` | 
`{slot} public void `[`show`](#class_view_1a913b840fc8042436555b89878feacb76)`()` | 

## Members

#### `public inline  `[`View`](#class_view_1a3fd5b2cd3d7ccfc51dd4b2730833180c)`(QWidget * parent)` 

#### `public virtual  `[`~View`](#class_view_1ad0f3ade04bca4e74b8868e63729bad86)`() = default` 

#### `{signal} public void `[`leftValuesAreSet`](#class_view_1a96f2fd0ed3467a0e5072e9a4a5593395)`(QVector< QString > values)` 

#### `{signal} public void `[`rightValuesAreSet`](#class_view_1aef26164c727b9a1b83ca0e84c00a0060)`(QVector< QString > values)` 

#### `{signal} public void `[`leftTypeIsSet`](#class_view_1ae0775d09884cd6b001829df4276e407c)`(QString type)` 

#### `{signal} public void `[`rightTypeIsSet`](#class_view_1a29e8b493fdbca2747da4ffa855ab966c)`(QString type)` 

#### `{signal} public void `[`operationIsSet`](#class_view_1af4cf1863986a0fac18d6da46c97329de)`(QString opt)` 

#### `{signal} public void `[`getResult`](#class_view_1ac05f93e75953488aa1a5a3f813603032)`()` 

#### `{signal} public void `[`reset`](#class_view_1a84eea48d2036da09640369d7997d957b)`()` 

#### `{signal} public void `[`lastOperation`](#class_view_1ae52f108d479e4d38f13ffc1ad97f7d5c)`()` 

#### `{signal} public void `[`done`](#class_view_1af0a5104e717bfe94ae35a1dfd9d5e183)`()` 

#### `{slot} public void `[`setAvailableOperations`](#class_view_1a203ab36b8546f1d9dc630bd7c0536e67)`(const QVector< QString > operations)` 

#### `{slot} public void `[`setPermittedOperations`](#class_view_1a5b3c08e11f2aece6c28c9b36e41ae35a)`(const QVector< QString > operations)` 

#### `{slot} public void `[`setLeftTypes`](#class_view_1a80c90f9167a8bc834d8c2f25be9e5f0d)`(const QVector< QString > types)` 

#### `{slot} public void `[`setLeftFields`](#class_view_1aa5db4d4ea2851a9ff4e923e38d219bec)`(const int & fields)` 

#### `{slot} public void `[`setRightTypes`](#class_view_1a26bb1996d32f29476ba3c0b5c01561fc)`(const QVector< QString > types)` 

#### `{slot} public void `[`setRightFields`](#class_view_1a63b329facfe2280261b7f01b582eadf9)`(const int & fields)` 

#### `{slot} public void `[`setResult`](#class_view_1a2d78db2bd23a6dd80bfeae64f4c3fdd3)`(const QVector< QString > result)` 

#### `{slot} public void `[`setResultFields`](#class_view_1ad3f5b700bd33a72bebc6efdbad2d17eb)`(const int & fields)` 

#### `{slot} public void `[`update`](#class_view_1a8caf26d67197c101c37da5c9cddfb534)`()` 

#### `{slot} public void `[`show`](#class_view_1a913b840fc8042436555b89878feacb76)`()` 

# class `YCbCr` 

```
class YCbCr
  : public RGB
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`YCbCr`](#class_y_cb_cr_1ab6929e8e39ce4bd2d554a9e6701def62)`(double _y,double _cb,double _cr)` | 
`public  `[`YCbCr`](#class_y_cb_cr_1ac13cfb8d36930918735eafa784086664)`(const `[`Color`](#class_color)` * from)` | 
`public  `[`YCbCr`](#class_y_cb_cr_1a145e99c53a8475e4f5300b74b49cb3e7)`(const `[`YCbCr`](#class_y_cb_cr)` & from)` | 
`public virtual int `[`getNumberOfComponets`](#class_y_cb_cr_1ac2291a443694e93c3105181f8202616c)`() const` | [RGB::getNumberOfComponets](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345).
`public virtual void `[`setComponents`](#class_y_cb_cr_1a2d4416e42914e6918b02d682fd1a729c)`(QVector< double > componets)` | [RGB::setComponents](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36) set the components inside the object.
`public virtual QString `[`getRappresentation`](#class_y_cb_cr_1aa040fae2bc6949f06e89f4abb1dc3e54)`() const` | [RGB::getRappresentation](#class_r_g_b_1a745d03e1bf66224b0ce39ac9fa92aa6a) returns the meaning of the values contained in [getComponents()](#class_y_cb_cr_1a269979ae2a9769c037c3d2121f0eeb68)
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_y_cb_cr_1ad0279aff55fd5f5df1950938fe4128a4)`() const` | [RGB::negate](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_y_cb_cr_1a80f0afa7e4ee078cccf717bb3ecd84ed)`(const `[`Color`](#class_color)` * c) const` | [RGB::mix](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9).
`public `[`Color`](#class_color)` * `[`getCIE`](#class_y_cb_cr_1a85e4db6310fcf1cb1153a55c2c088beb)`(double y,double cb,double cr)` | 
`public virtual QVector< double > `[`getComponents`](#class_y_cb_cr_1a269979ae2a9769c037c3d2121f0eeb68)`() const` | RGB::getComponent returns component in [RGB](#class_r_g_b) class;.
`public virtual `[`Color`](#class_color)` * `[`operator/`](#class_y_cb_cr_1ad765db897398dd2c8adcc542813e9e85)`(const int & div) const` | [RGB::operator /](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80) new [RGB](#class_r_g_b) object with value divided.

## Members

#### `public  `[`YCbCr`](#class_y_cb_cr_1ab6929e8e39ce4bd2d554a9e6701def62)`(double _y,double _cb,double _cr)` 

#### `public  `[`YCbCr`](#class_y_cb_cr_1ac13cfb8d36930918735eafa784086664)`(const `[`Color`](#class_color)` * from)` 

#### `public  `[`YCbCr`](#class_y_cb_cr_1a145e99c53a8475e4f5300b74b49cb3e7)`(const `[`YCbCr`](#class_y_cb_cr)` & from)` 

#### `public virtual int `[`getNumberOfComponets`](#class_y_cb_cr_1ac2291a443694e93c3105181f8202616c)`() const` 

[RGB::getNumberOfComponets](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345).

#### Returns
int

#### `public virtual void `[`setComponents`](#class_y_cb_cr_1a2d4416e42914e6918b02d682fd1a729c)`(QVector< double > componets)` 

[RGB::setComponents](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36) set the components inside the object.

#### Parameters
* `componets`

#### `public virtual QString `[`getRappresentation`](#class_y_cb_cr_1aa040fae2bc6949f06e89f4abb1dc3e54)`() const` 

[RGB::getRappresentation](#class_r_g_b_1a745d03e1bf66224b0ce39ac9fa92aa6a) returns the meaning of the values contained in [getComponents()](#class_y_cb_cr_1a269979ae2a9769c037c3d2121f0eeb68)

#### Returns
QString

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_y_cb_cr_1ad0279aff55fd5f5df1950938fe4128a4)`() const` 

[RGB::negate](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69).

#### Returns
return a new [Color](#class_color) object with a new complementary color

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_y_cb_cr_1a80f0afa7e4ee078cccf717bb3ecd84ed)`(const `[`Color`](#class_color)` * c) const` 

[RGB::mix](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9).

#### Parameters
* `Color*` t_c 

#### Returns
a new [Color](#class_color) object with the mixed Colors

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_y_cb_cr_1a85e4db6310fcf1cb1153a55c2c088beb)`(double y,double cb,double cr)` 

#### `public virtual QVector< double > `[`getComponents`](#class_y_cb_cr_1a269979ae2a9769c037c3d2121f0eeb68)`() const` 

RGB::getComponent returns component in [RGB](#class_r_g_b) class;.

#### Returns
QVector<double>

#### `public virtual `[`Color`](#class_color)` * `[`operator/`](#class_y_cb_cr_1ad765db897398dd2c8adcc542813e9e85)`(const int & div) const` 

[RGB::operator /](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80) new [RGB](#class_r_g_b) object with value divided.

#### Parameters
* `int` div 

#### Returns
[RGB](#class_r_g_b)

# class `YUV` 

```
class YUV
  : public RGB
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`YUV`](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84)`(double _y,double _u,double _v)` | 
`public  `[`YUV`](#class_y_u_v_1a80778948bf90243f1424e06f9dfbbbf1)`(const `[`Color`](#class_color)` * from)` | 
`public  `[`YUV`](#class_y_u_v_1af6de31964471999a64e34af00ef6e196)`(const `[`YUV`](#class_y_u_v)` & from)` | 
`public virtual QString `[`getRappresentation`](#class_y_u_v_1af14d8838d1b05fc5414674d462e5e5c8)`() const` | [RGB::getRappresentation](#class_r_g_b_1a745d03e1bf66224b0ce39ac9fa92aa6a) returns the meaning of the values contained in [getComponents()](#class_y_u_v_1ad90109db3486e61e248e274a7690824a)
`public virtual `[`Color`](#class_color)` * `[`negate`](#class_y_u_v_1a079872ae88552066ce1abb39cc0a40de)`() const` | [RGB::negate](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69).
`public virtual `[`Color`](#class_color)` * `[`mix`](#class_y_u_v_1ab152a4ea37eaa67df0b38882c2099da3)`(const `[`Color`](#class_color)` * c) const` | [RGB::mix](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9).
`public `[`Color`](#class_color)` * `[`getCIE`](#class_y_u_v_1a56f11c27f1659c30ebd20c929704e004)`(double y,double u,double v)` | 
`public virtual QVector< double > `[`getComponents`](#class_y_u_v_1ad90109db3486e61e248e274a7690824a)`() const` | RGB::getComponent returns component in [RGB](#class_r_g_b) class;.
`public virtual int `[`getNumberOfComponets`](#class_y_u_v_1a46eded5c13a0c2b2e9bbf05d4a2f9c7c)`() const` | [RGB::getNumberOfComponets](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345).
`public virtual void `[`setComponents`](#class_y_u_v_1a622daf7a688da4a227b63deb412c0d46)`(QVector< double > componets)` | [RGB::setComponents](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36) set the components inside the object.
`public virtual `[`Color`](#class_color)` * `[`operator/`](#class_y_u_v_1a1b9300c00323eca16fc4bb028964e85f)`(const int & div) const` | [RGB::operator /](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80) new [RGB](#class_r_g_b) object with value divided.

## Members

#### `public  `[`YUV`](#class_y_u_v_1aafa9b0e5ddae51a501c13c9c4b106b84)`(double _y,double _u,double _v)` 

#### `public  `[`YUV`](#class_y_u_v_1a80778948bf90243f1424e06f9dfbbbf1)`(const `[`Color`](#class_color)` * from)` 

#### `public  `[`YUV`](#class_y_u_v_1af6de31964471999a64e34af00ef6e196)`(const `[`YUV`](#class_y_u_v)` & from)` 

#### `public virtual QString `[`getRappresentation`](#class_y_u_v_1af14d8838d1b05fc5414674d462e5e5c8)`() const` 

[RGB::getRappresentation](#class_r_g_b_1a745d03e1bf66224b0ce39ac9fa92aa6a) returns the meaning of the values contained in [getComponents()](#class_y_u_v_1ad90109db3486e61e248e274a7690824a)

#### Returns
QString

#### `public virtual `[`Color`](#class_color)` * `[`negate`](#class_y_u_v_1a079872ae88552066ce1abb39cc0a40de)`() const` 

[RGB::negate](#class_r_g_b_1a7aad38ac17ec3201c65f8f5e90637b69).

#### Returns
return a new [Color](#class_color) object with a new complementary color

#### `public virtual `[`Color`](#class_color)` * `[`mix`](#class_y_u_v_1ab152a4ea37eaa67df0b38882c2099da3)`(const `[`Color`](#class_color)` * c) const` 

[RGB::mix](#class_r_g_b_1aa022866e33474ab64f81d367c6b030b9).

#### Parameters
* `Color*` t_c 

#### Returns
a new [Color](#class_color) object with the mixed Colors

#### `public `[`Color`](#class_color)` * `[`getCIE`](#class_y_u_v_1a56f11c27f1659c30ebd20c929704e004)`(double y,double u,double v)` 

#### `public virtual QVector< double > `[`getComponents`](#class_y_u_v_1ad90109db3486e61e248e274a7690824a)`() const` 

RGB::getComponent returns component in [RGB](#class_r_g_b) class;.

#### Returns
QVector<double>

#### `public virtual int `[`getNumberOfComponets`](#class_y_u_v_1a46eded5c13a0c2b2e9bbf05d4a2f9c7c)`() const` 

[RGB::getNumberOfComponets](#class_r_g_b_1a7561d57d6706bc25ea10762d906b2345).

#### Returns
int

#### `public virtual void `[`setComponents`](#class_y_u_v_1a622daf7a688da4a227b63deb412c0d46)`(QVector< double > componets)` 

[RGB::setComponents](#class_r_g_b_1acf213178f2029a5f304d62b87dbb6b36) set the components inside the object.

#### Parameters
* `componets`

#### `public virtual `[`Color`](#class_color)` * `[`operator/`](#class_y_u_v_1a1b9300c00323eca16fc4bb028964e85f)`(const int & div) const` 

[RGB::operator /](#class_r_g_b_1a9d250e0f58e7ae7d4c69ced724da6f80) new [RGB](#class_r_g_b) object with value divided.

#### Parameters
* `int` div 

#### Returns
[RGB](#class_r_g_b)

Generated by [Moxygen](https://sourcey.com/moxygen)