package com.example.myapplication;

import android.util.Log;

import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;


public class ReflectUtils {
    /**
     * 用于缓存已反射过的method，不支持 同一个类里面的同名且同参数个数的函数，
     * 会获取此函数名的第一个method，有可能会报参数类型不匹配 argument type mismatch
     *
     * classname,methodname,args size.
     */
    public static Map<Class,Map<String,Map<Integer,Method>>> mCacheMethodMap = new HashMap<>();
    public static Class getClass(String className) {
        try {
            return Class.forName(className);
        }catch(Exception v0) {
            Log.e("ReflectUtils", "className not found:" + className);
            return null;
        }
    }
    private static Map<Integer,Method> getMethodFromCache(Class aClass, String methodName){
        Map<String,Map<Integer,Method>> map = mCacheMethodMap.get(aClass);
        if(map == null){
            map = new HashMap<>();
            mCacheMethodMap.put(aClass,map);
        }
        Map<Integer,Method> methods = map.get(methodName);
        if(methods == null){
            methods = new HashMap<>();
            map.put(methodName,methods);
        }
        return methods;
    }
    public static Object getStaticField(String className,String fieldName){
        try {
            return Class.forName(className).getDeclaredField(fieldName);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
    public static Method getMethod(Class aClass, String methodName, Class[] args) {
        if(args == null) args = new Class[0];
        Map<Integer,Method> methods = getMethodFromCache(aClass,methodName);
        Method method = methods.get(Integer.valueOf(args.length));
        if(method != null){
            return method;
        }
        if(aClass != null) {
            if(!isEmpty(methodName)) {
                try {
                    method = aClass.getDeclaredMethod(methodName, args);
                    method.setAccessible(true);
                }catch(Exception e) {
                    Log.e("ReflectUtils", methodName + ", not such method.");
                }
            }
        }
        if(method != null){
            methods.put(Integer.valueOf(args.length),method);
        }
        return method;
    }
    
    public static Method getMethod(String methodName, Class aClass, Object[] args){
        if(args == null) args = new Object[0];
        Map<Integer,Method> methodsMap = getMethodFromCache(aClass,methodName);
        Method method = methodsMap.get(Integer.valueOf(args.length));
        if(method != null){
            return method;
        }
        try {
            Method[] methods = aClass.getDeclaredMethods();
            for(int idx = 0; idx < methods.length; idx++) {
                method = methods[idx];
                if(method.getName().equals(methodName)) {
                    Class[] classes = method.getParameterTypes();
                    if(args == null && (classes == null || classes.length == 0)) {
                        break;
                    }else if(args.length == classes.length) {
                        break;
                    }
                }
            }
//            Class[] argClass = new Class[args.length];
//            for(int i=0;i<args.length;i++){
//                argClass[i] = args[i].getClass();
//            }
//            getMethod(aClass,methodName,argClass);
        }catch (Exception e){
            e.printStackTrace();
        }
        if(method != null){
            method.setAccessible(true);
            methodsMap.put(Integer.valueOf(args.length),method);
        }
        return method;
    }
    
    public static Method getMethod(String methodName, Object instance, Object[] args){
        return getMethod(methodName, instance.getClass(), args);
    }
    
    public static Object invokeMethod(String methodName, Object instance, Object[] args){
        Method method = getMethod(methodName, instance, args);
        try {
            return method.invoke(instance, args);
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        return null;
    }
    
    public static Object invokeStaticMethod(String methodName, String className, Object[] args){
        try {
            return getMethod(methodName, Class.forName(className), args).invoke(null, args);
        }catch(Exception e) {
            e.printStackTrace();
        }
        return null;
    }
    
    public static Object invokeStaticMethod(String methodName, Class aClass, Object[] args){
        Method method = getMethod(methodName, aClass, args);
        try {
            return method.invoke(null, args);
        }catch(Exception e) {
            e.printStackTrace();
        }
        return null;
    }
    
    private static boolean isEmpty(String str) {
        return str == null || str.trim().length() == 0;
    }
    
    public static boolean isMethodExist(String className, String methodName) {
        if(className != null && methodName != null) {
            try {
                Method[] methods = Class.forName(className).getMethods();
                for(int idx = 0;idx < methods.length;idx++){
                    if(methodName.equals(methods[idx].getName())){
                        return true;
                    }
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return false;
    }
}
