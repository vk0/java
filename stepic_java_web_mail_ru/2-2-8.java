// Какие ошибки компиляции есть в следующем коде:

// class A{

//             public Map<Integer, Integer> map = new HashMap<>();

//             public int get(int key){
//                         return map.get(key);
//             }

//             public void set(int key, Object value){
//                         map.put(key, value);
//             }
//  }

добавление в карту обьектов типа Object (map.put(key, value))

// Error:(14, 22) java: incompatible types: java.lang.Object cannot be converted to java.lang.Integer