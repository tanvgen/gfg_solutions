<h2><a href="https://www.geeksforgeeks.org/problems/nth-catalan-number0817/1?page=2&category=Dynamic%20Programming&sortBy=submissions">Nth catalan number</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a number <strong>N</strong>. The task is to find the <strong>N<sup>th</sup> catalan number</strong>.<br>The first few Catalan numbers for <strong>N = 0, 1, 2, 3, </strong>… are <strong>1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …</strong></span></p>
<p><span style="font-size: 14pt;"><strong>Catalan Number&nbsp;</strong>for <strong>N</strong> is equal to the number of expressions containing <strong>N</strong> pairs of paranthesis that are correct matched, i.e., for each of the N '(' there exist N ')' on there right and vice versa.</span></p>
<p><span style="font-size: 14pt;">Since answer can be huge return answer modulo <strong>1e9+7</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> Positions start from 0 as shown above.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input:
</strong><span style="font-size: 18px;">N = 3
</span><strong style="font-size: 18px;">Output: 5<br>Explanation:<br></strong><span style="font-size: 18px;"><strong>((())),(()()),()(()),(())(),()()()</strong></span><strong style="font-size: 18px;"><br></strong></span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>N = 4
<strong>Output: </strong>14</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>Complete <strong>findCatalan()</strong>&nbsp;function that takes n as an argument and returns the N<sup>th</sup> Catalan number. The output is printed by the driver code.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(N^2).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(N).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Mathematical</code>&nbsp;<code>Algorithms</code>&nbsp;