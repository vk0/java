package ru.csc.java2014.testing.demo2;

import org.junit.Test;

import java.util.HashMap;
import java.util.Map;

import static org.fest.assertions.api.Assertions.*;

public class HashMapTest {

    @Test
    public void default_constructor_should_create_empty_map() {
        Map<String, String> map = new HashMap<String, String>();

        assertThat(map).isEmpty();
        assertThat(map).hasSize(0);
        assertThat(map).doesNotContainKey("x");

        assertThat(map.entrySet().iterator().hasNext()).isFalse();
    }


    @Test
    public void collection_constructor_should_copy_all_content() {
        Map<String, String> originalMap = new HashMap<String, String>();
        originalMap.put("a", "b");
        originalMap.put("c", "d");

        Map<String, String> copiedMap = new HashMap<String, String>(originalMap);

        assertThat(copiedMap)
                .describedAs("copied map")
                .hasSize(2)
                .isEqualTo(originalMap)
                .isNotSameAs(originalMap);

        originalMap.put("e", "f");

        assertThat(copiedMap)
                .hasSize(2)
                .doesNotContain(entry("e", "f"))
                .isNotEqualTo(originalMap);
    }
}
