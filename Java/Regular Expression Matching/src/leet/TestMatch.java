package leet;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.Test;

class TestMatch {
	@Test
	void test1() throws Exception {
		assertEquals(true,Solution.isMatch("", ""));			//true
	}
	
	@Test
	void test2() throws Exception {
		assertEquals(true,Solution.isMatch("a", "a"));			//true
	}
	
	@Test
	void test3() throws Exception {
		assertEquals(true,Solution.isMatch("aa", "aa"));		//true
	}
	
	@Test
	void test4() throws Exception {
		assertEquals(true,Solution.isMatch("aaaa", "aaaa"));	//true
	}
	
	@Test
	void test5() throws Exception {
		assertEquals(false,Solution.isMatch("aa", "a"));		//false
	}
	
	@Test
	void test6() throws Exception {
		assertEquals(false,Solution.isMatch("aaa", "aa"));		//false
	}
	
	@Test
	void test7() throws Exception {
		assertEquals(true,Solution.isMatch("a", "."));			//true
	}
	
	@Test
	void test8() throws Exception {
		assertEquals(true,Solution.isMatch("aa", "a*"));		//true
	}
		
	@Test
	void test9() throws Exception {
		assertEquals(true,Solution.isMatch("aa", ".*"));		//true
	}
	
	@Test
	void test10() throws Exception {
		assertEquals(false,Solution.isMatch("ab", "."));		//false
	}
	
	@Test
	void test11() throws Exception {
		assertEquals(true,Solution.isMatch("aab", "c*a*b"));	//true
	}
	
	@Test
	void test12() throws Exception {
		assertEquals(true,Solution.isMatch("aaab", "a*ab"));	//true
	}
	
	@Test
	void test13() throws Exception {
		assertEquals(true,Solution.isMatch("a", "a*aa*"));		//true
	}
	
	@Test
	void test14() throws Exception {
		assertEquals(true,Solution.isMatch("aa", ".a"));			//true
	}
}
