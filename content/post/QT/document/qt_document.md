---
title: "Qt document"
date: 2019-01-23T09:15:07+08:00
draft: true
---

# [The QML Reference](http://doc.qt.io/qt-5/qmlreference.html)

## [QML Object Attributes](http://doc.qt.io/qt-5/qtqml-syntax-objectattributes.html)

- This id must begin with a lower-case letter or an underscore, and cannot contain characters other than letters, numbers and underscores.

### Property Attributes
- property's value can be read and modified by other objects. 
- Property names must begin with a lower case letter and can only contain letters, numbers and underscores.

- Properties are type safe. A property can only be assigned a value that matches the property type.

#### Property Aliases

- Signal Attributes
  - An object can be notified through a signal handler whenever a particular signal is emitted. A signal handler is declared with the syntax on<Signal> where <Signal> is the name of the signal, with the first letter capitalized. The signal handler must be declared within the definition of the object that emits the signal, and the handler should contain the block of JavaScript code to be executed when the signal handler is invoked.

#### Default Properties
- An object definition can have a single default property. A default property is the property to which a value is assigned if an object is declared within another object's definition without declaring it as a value for a particular property.
- A read-only property cannot also be a default property.

## [Property Binding](https://doc.qt.io/qt-5/qtqml-syntax-propertybinding.html)
- A binding can contain any valid JavaScript expression or statement, as QML uses a standards compliant JavaScript engine. Bindings can access object properties, call methods and use built-in JavaScript objects such as Date and Math. 
- A property with a binding is automatically updated as necessary. However, if the property is later assigned a static value from a JavaScript statement, the binding will be removed.
### Debugging overwriting of bindings
- To help developers track down problems of this kind, the QML engine is able to emit messages whenever a binding is lost due to imperative assignments.

## [JavaScript Host Environment](https://doc.qt.io/qt-5/qtqml-javascript-hostenvironment.html)
- the QML runtime implements the ECMAScript Language Specification standard. This provides access to all of the built-in types and functions defined by the standard, which is the same edition commonly implemented by browsers.
### JavaScript Objects and Functions
### JavaScript Environment Restrictions
- JavaScript's automatic creation of undeclared variables is an implicit modification of the global object, and is prohibited in QML.
#### Global code is run in a reduced scope.
- This restriction exists as the QML environment is not yet fully established. To run code after the environment setup has completed, see JavaScript in Application Startup Code.
#### The value of this is undefined in QML in the majority of contexts.

## [JavaScript Expressions in QML Documents](https://doc.qt.io/qt-5/qtqml-javascript-expressions.html)
### JavaScript in application startup code
- the best place to write application startup code is in the Component.onCompleted handler of the top-level object, because this object emits Component.completed when the QML environment is fully established.
- Any object in a QML file - including nested objects and nested QML component instances - can use this attached property. If there is more than one onCompleted() handler to execute at startup, they are run sequentially in `an undefined order`.
- Likewise, every Component emits a destruction() signal just before being destroyed.

## [Signal and Handler Event System](https://doc.qt.io/qt-5/qtqml-syntax-signals.html)
- A signal is automatically emitted when the value of a QML property changes. This type of signal is a property change signal and signal handlers for these signals are written in the form on<Property>Changed, where <Property> is the name of the property, with the first letter capitalized.
- Even though the TapHandler documentation does not document a signal handler named onPressedChanged, the signal is implicitly provided by the fact that the pressed property exists.
- In some cases it may be desirable to access a signal outside of the object that emits it. For these purposes, the QtQuick module provides the Connections type for connecting to signals of arbitrary objects. A Connections object can receive any signal from its specified target.
- An attached signal handler receives a signal from an attaching type rather than the object within which the handler is declared.
### Adding signals to custom QML types
- A signal is emitted by invoking the signal as a method.
- However, using the connect method allows a signal to be received by multiple methods as shown earlier, which would not be possible with signal handlers as they must be uniquely named. Also, the connect method is useful when connecting signals to dynamically created objects.

## [First Steps with QML](https://doc.qt.io/qt-5/qmlfirststeps.html#)

One of the great advantages of using QML to define a user interface is that it allows the user interface designer to define how the application should react to events with simple JavaScript expressions. In QML, we refer to those events as signals and these signals are handled by signal handlers.

## [Deploying QML Applications](https://doc.qt.io/qt-5/qtquick-deployment.html)
If application.qml does not have any graphical components, or if it is preferred to avoid QQuickView for other reasons, the QQmlEngine can be constructed directly instead.

## [QML Coding Conventions](https://doc.qt.io/qt-5/qml-codingconventions.html)

## [Overview - QML and C++ Integration](https://doc.qt.io/qt-5/qtqml-cppintegration-overview.html#defining-qml-types-from-c)




# pro files

[Creating Project Files](https://doc.qt.io/qt-5/qmake-project-files.html)
- To include the # character in variable assignments, it is necessary to use the contents of the built-in LITERAL_HASH variable.

[Variables](https://doc.qt.io/qt-5/qmake-variable-reference.html#installs)
Variable | Contents
-- | --
CONFIG | General project configuration options.
DESTDIR | The directory in which the executable or binary file will be placed.
FORMS | A list of UI files to be processed by the user interface compiler (uic).
HEADERS | A list of filenames of header (.h) files used when building the project.
QT | A list of Qt modules used in the project.
RESOURCES | A list of resource (.qrc) files to be included in the final project. See the The Qt Resource System for more information about these files.
SOURCES | A list of source code files to be used when building the project.
TEMPLATE | The template to use for the project. This determines whether the output of the build process will be an application, a library, or a plugin. 

[qmake Language](https://doc.qt.io/qt-5/qmake-language.html)

- The ! symbol is used to negate the test. 
- Nested scopes can be joined together using colons.
    - Generally, the : operator behaves like a logical AND operator, joining together a number of conditions, and requiring all of them to be true. 
    - You may also use the : operator to perform single line conditional assignments. 
- The contents of a variable can be read by prepending the variable name with `$$`.


## summary
[QObject Class](https://doc.qt.io/qt-5/qobject.html)
- Q_OBJECT
  
    The Q_OBJECT macro must appear in the private section of a class definition that declares its own signals and slots or that uses other services provided by Qt's meta-object system.
    This macro requires the class to be a subclass of QObject.

- Q_PROPERTY( ...)
    
    The property name and type and the READ function are required. The type can be any type supported by QVariant, or it can be a user-defined type. The other items are optional, but a WRITE function is common. The attributes default to true except USER, which defaults to false.

- Q_INVOKABLE
  
  Apply this macro to declarations of member functions to allow them to be invoked via the meta-object system. The macro is written before the return type, as shown in the following example:



<https://doc.qt.io/qt-5/qqmlengine.html>

- qmlRegisterType

    Note that it's perfectly reasonable for a library to register types to older versions than the actual version of the library. Indeed, it is normal for the new library to allow QML written to previous versions to continue to work, even if more advanced versions of some of its types are available.

<https://doc.qt.io/qt-5/qmlapplications.html>

- QML
    QML is a user interface specification and programming language. 
- Qt Quick
    Qt Quick is the standard library of types and functionality for QML.

<https://doc.qt.io/qt-5/qtquickcontrols-index.html>
- Qt Quick Controls 2 
    Qt Quick Controls 2 provides a set of controls that can be used to build complete interfaces in Qt Quick.

## [The Meta-Object System](https://doc.qt.io/qt-5/metaobjects.html)
To provid the signals and slots mechanism for communication between objects is the main reason for introducing the system.
Therefore, we strongly recommend that all subclasses of QObject use the Q_OBJECT macro regardless of whether or not they actually use signals, slots, and properties. 

## [Defining QML Types from C++](https://doc.qt.io/qt-5/qtqml-cppintegration-definetypes.html)
- a C++ class can be registered with the QML type system to enable the class to be used as a data type within QML code. 
- Note that all C++ types registered with the QML type system must be QObject-derived, even if they are non-instantiable.
- Enum values for registered types in QML should start with a capital.

## [Exposing Attributes of C++ Types to QML](https://doc.qt.io/qt-5/qtqml-cppintegration-exposecppattributes.html)
- A property is a class data member with an associated read function and optional write function.
- For maximum interoperability with QML, any property that is writable should have an associated NOTIFY signal that is emitted whenever the property value has changed. 
- This is because QList is not a QObject-derived type, and so cannot provide the necessary QML property characteristics through the Qt meta object system, such as signal notifications when a list is modified.
- Any read-only object-type property is accessible from QML code as a grouped property. 
- If a C++ method has a parameter with a QObject* type, the parameter value can be passed from QML using an object id or a JavaScript var value that references the object.

## [Writing QML Extensions with C++](https://doc.qt.io/qt-5/qtqml-tutorials-extending-qml-example.html)
- 

## [Embedding C++ Objects into QML with Context Properties](https://doc.qt.io/qt-5/qtqml-cppintegration-contextproperties.html)
- The ability to inject C++ data into a QML object is made possible by the QQmlContext class. This class exposes data to the context of a QML object so that the data can be referred to directly from within the scope of the QML code.

- Since all expressions evaluated in QML are evaluated in a particular context, if the context is modified, all bindings in that context will be re-evaluated. Thus, context properties should be used with care outside of application initialization, as this may lead to decreased application performance.

## [Object Trees & Ownership](https://doc.qt.io/qt-5/objecttrees.html)  !!!
- When QObjects are created on the heap, No QObject is deleted twice, regardless of the order of destruction.
- When QObjects are created on the stack, the order of destruction may present a problem.

## [Data Type Conversion Between QML and C++](https://doc.qt.io/qt-5/qtqml-cppintegration-data.html)
- When data is transferred from C++ to QML, the ownership of the data always remains with C++.
- Classes provided by the Qt GUI module, such as QColor, QFont, QQuaternion and QMatrix4x4, are only available from QML when the Qt Quick module is included.
- Any QObject-derived class may be used as a type for the exchange of data between QML and C++, providing the class has been registered with the QML type system.
- The engine allows the registration of both instantiable and non-instantiable types. 

## [Concepts - Visual Parent in Qt Quick](https://doc.qt.io/qt-5/qtquick-visualcanvas-visualparent.html)
- Most Qt Quick hierarchy crawling algorithms, especially the rendering algorithms, only consider the visual parent hierarchy.
- The Item data property is its default property.
- Additionally, a parent item will not automatically clip its children to visually contain them within the parent's visual bounds, unless its clip property is set to true.
- Z values only affect stacking compared to siblings and the parent item. Z values below 0 will stack below the parent, and if z values are assigned then siblings will stack in z-order (with creation order used to break ties). 

## [The Property System](https://doc.qt.io/qt-5/properties.html)
- The enumeration type must be registered with the Meta-Object System using the Q_ENUM() macro. Registering an enumeration type makes the enumerator names available for use in calls to QObject::setProperty(). 

## [QMetaObject Class](https://doc.qt.io/qt-5/qmetaobject.html)
- The QMetaObject class contains meta-information about Qt objects.

- The Qt Meta-Object System in Qt is responsible for the signals and slots inter-object communication mechanism, runtime type information, and the Qt property system. A single QMetaObject instance is created for each QObject subclass that is used in an application, and this instance stores all the meta-information for the QObject subclass. This object is available as QObject::metaObject().

## [Qt Namespace](https://doc.qt.io/qt-5/qt.html)
- The Qt namespace contains miscellaneous identifiers used throughout the Qt library. 



## [QAbstractTableModel Class](https://doc.qt.io/qt-5/qabstracttablemodel.html)
- When subclassing QAbstractTableModel, you must implement rowCount(), columnCount(), and data(). Default implementations of the index() and parent() functions are provided by QAbstractTableModel. Well behaved models will also implement headerData().
- it is important to call the appropriate functions so that all connected views are aware of any changes

## [QModelIndex Class](https://doc.qt.io/qt-5/qmodelindex.html)
- The QModelIndex class is used to locate data in a data model.
- An invalid model index can be constructed with the QModelIndex constructor. Invalid indexes are often used as parent indexes when referring to top-level items in a model.

## [Component QML Type](https://doc.qt.io/qt-5/qml-qtqml-component.html)
- Components are reusable, encapsulated QML types with well-defined interfaces.
- The component encapsulates the QML types within, as if they were defined in a separate QML file, and is not loaded until requested.
- A QML document has a single top-level item that defines the behavior and properties of that component, and cannot define properties or behavior outside of that top-level item. 

## [Qt Quick Controls Configuration File](https://doc.qt.io/qt-5/qtquickcontrols2-configuration.html)

## [Window QML Type](https://doc.qt.io/qt-5/qml-qtquick-window-window.html)
A Window can be declared inside an Item or inside another Window; in that case the inner Window will automatically become "transient for" the outer Window: that is, most platforms will show it centered upon the outer window by default, and there may be other platform-dependent behaviors, depending also on the flags. If the nested window is intended to be a dialog in your application, you should also set flags to Qt.Dialog, because some window managers will not provide the centering behavior without that flag. You can also declare multiple windows inside a top-level QtObject, in which case the windows will have no transient relationship.