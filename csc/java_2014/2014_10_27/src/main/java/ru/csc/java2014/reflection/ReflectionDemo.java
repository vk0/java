package ru.csc.java2014.reflection;

import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Modifier;
import java.util.Collection;

public class ReflectionDemo {

    public static void main(String[] args) throws Exception {
        Class<?> multiSetClass = Class.forName("ru.csc.java2014.reflection.MultiSetImpl");

        boolean implementsMultiSet = MultiSet.class.isAssignableFrom(multiSetClass);
        System.out.println("Implements MultiSet interface: " + implementsMultiSet);

        Constructor<?> defaultConstructor = null;
        Constructor<?> collectionConstructor = null;
        for (Constructor<?> constructor : multiSetClass.getConstructors()) {
            Class<?>[] parameterTypes = constructor.getParameterTypes();
            if (parameterTypes.length == 0) {
                defaultConstructor = constructor;
            } else if (parameterTypes.length == 1 && parameterTypes[0].equals(Collection.class)) {
                collectionConstructor = constructor;
            }
        }
        System.out.println("Default constructor present: " + (defaultConstructor != null));
        System.out.println("Constructor from collection present: " + (collectionConstructor != null));

        Class<?> superclass = multiSetClass.getSuperclass();
        if (!Object.class.equals(superclass)) {
            System.out.println("Extends " + superclass.getCanonicalName());
        }

        System.out.println("Fields:");
        Class<?> currentClass = multiSetClass;
        do {
            for (Field field : currentClass.getDeclaredFields()) {
                if ((field.getModifiers() & Modifier.STATIC) == 0) {
                    System.out.println(
                            "- " + field.getType().getCanonicalName() + " " + field.getName()
                            + " (in " + currentClass.getCanonicalName() + ")");
                }
            }
            currentClass = currentClass.getSuperclass();
        } while (!Object.class.equals(currentClass));


        MultiSet multiSetInstance = (MultiSet) defaultConstructor.newInstance();
    }
}
