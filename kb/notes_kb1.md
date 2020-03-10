# Notes on  "Test Driven Development by Example" by Kent Beck

[Another link][1]

This is the first week of my PIP
## Part I: The Money Example
1. [Multi-Currency Money](#Multi-Currency-Money)
2. [Degenerate Objects](#Degenerate-Objects)
3. [Equality for All](#Equality-for-All)
4. [Privacy](#Privacy)
5. [Franc-ly Speaking](#Franc-ly-Speaking)
6. [Equality for All, Redux](#Equality-for-All,-Redux)
7. [Apples and Oranges](#Apples-and-Oranges)
8. [Making Objects](#Making-Objects)


Part I
1. Quickly add a test (start smallest)
2. Run all tests and see the new one fail, "explore" learn by fix wrongs
3. Make a little change - iterate frequent, cover little by little 
4. Run all tests and see them all succeed - 
5. Refactor to remove duplicatrion - clear the path to improve and possible optimize

## 1 Multi-Currency Money
-----------
`TODO`

$5 + 10 CHF = $10 if rate is 2:1

**$5 * 2 = $10**


What set of tests, when passed, will demostrate the presence of code we are confident will compute the report correctly?
- Able to add in two different currencies and convert result given a set of xchange rates
- Able to multiply any `amount` (price per share) by a number (number off shares) and receive and amount

Make a TODO list - reminds us what we need to do, keep us focus, **item current working on** and ~~we finish this~~ thing. If we think of another test, we added it to the list,

- TODO/ Multiplication first: start with the test, the simpler is the second.
- Test: imagine the perfect interface. Start by how it will look from the outside, tgry the best possible and then work backwards.    
```
public void testMultiplication() {
  Dollar five = new Dollar(5);
  five.times(2);
  assertEqual(10, five.amount);
}
```
We have a failing test... and we want to go green as soon as possible

`TODO`
- $5 + 10 CHF = $10 if rate is 2:1
- **$5 * 2 = $10**
- Make `amount` private
- `Dollar` side effects?
- `Money` rounding ?

The test doesn't even run, needed: `class Dollar`, Constructor `Dollar (int amount) {}`, stub of `times()` and a `amount` field
It compiles but `10` vs `0` problem from _give me multi-currency_ to _make this test work, and then make the rest of the tests work_  we can do that!!

`int amount = 10;` but we need to generalize:
1. Add a little test
2. Run all tests and fail
3. Make a little change
4. Run the tests and succeed
5. Refactor to remove duplication

### Dependency and Duplication
root: **Dependency** between the code and the test. Goal: Make another test that "makes sense" w/o changing the code

> If dependency is the problem, duplication is the symptom. Most of the time is 'logic' duplication, same expression repeated. Objects can abstract away duplication -- eliminating duplication in programs, eliminates dependency (not common: as we are dealing with the symptoms) if we eliminate duplicate, we have higher chances to have our next test running with one and only one change

In our case duplication is in the data: `int amount = 5*2 ;` then move the setting of `amount` to the `times()` test still passes. Focus on doing small steps, then tailor to proper size. 

Pass the `5` to constructor, this is the `amount` and replace it in the `times()`, now the `2` is the `multiplier` 
```
void times(int multiplier) {
  amount *= multiplier;
}
```
`TODO`
- $5 + 10 CHF = $10 if rate is 2:1
- ~~$5 * 2 = $10~~
- Make `amount` private
- `Dollar` side effects?
- `Money` rounding ?

First test mark as DONE

### Summary
- MAde a list of the tests we needed to have working
- Told a story with a code snippet, how we want our operatiom
- Made the test compile with stubs
- Made the test pass by dcommiting horrible sins
- Gradualy generalize the production code: break down constants with variables
- Add items to our TODO rather than addressing them at once


## 2 Degenerate Objects
The general TDD cycle:
1. Write a test - write a story, invent the interface you wish you had, include all elements in the story
2. Make it run - get green quick, make note if solution takes more than 1 min and get back to get it green -excuse all for a moment 
3. Make it right - - put the sinful ways of the recent past behind you, step back onto the straight and narrow path of software righteousness, remove duplication

The goal is: **clean code that works**, you have to reverse it, first solve "that works" part and then solve the "clean code" part, vs. architecture-driven development

`TODO`
- $5 + 10 CHF = $10 if rate is 2:1
- ~~$5 * 2 = $10~~
- Make `amount` private
- **`Dollar` side effects?**
- `Money` rounding ?

We want something like
```
public void testMultiplication() {
  Dollar five = new Dollar(5);
  five.times(2);  # -- five changes to 10!
  assertEquals(10, five.amount);
  five.times(3);
  assertEquals(15, five.amount);
}
```
The code
```
public void testMultiplication() {
  Dollar five = new Dollar(5);
  Dollar product = five.times(2);
  assertEquals(10, product.amount);
  Dollar product = five.times(3);
  assertEquals(15, product.amount);
}

Dollar times(int multiplier) {
  return new Dollar(amount * multiplier);
}
```
`TODO`
- $5 + 10 CHF = $10 if rate is 2:1
- ~~$5 * 2 = $10~~
- Make `amount` private
- ~~`Dollar` side effects?~~
- `Money` rounding ?

Chapter 1 - stubs bogus implementation that evolve to do the job. Here we typed what we thought was the right implementation and gradually make it real. 
- **Fake It** return a constant, gradually change it w variables until you have the real code
- Use Obvious Implementation - type in the real stuff
Triangulation
- Translate a design objection (side effects) into a test case that failed because of the objection
- Got the code to compile quickly with a _stub_ implementation
- Make the test work by typing what it seemed to be the right code

The translation of a feeling -side effect like multiply the `Dollar` twice, into a test is a common theme of TDD. Talk cases, best way to achieve behavior.

## 3 Equality for All
Value Objects: no aliasing problems. Implications:
- all operations must return a new object
- should implement `equals()`
- if use `Dollars` as the key to a hash table, the you need to implement `hasCode()` if you implement `equals()`

`TODO`
- $5 + 10 CHF = $10 if rate is 2:1
- ~~$5 * 2 = $10~~
- Make `amount` private
- ~~`Dollar` side effects?~~
- `Money` rounding ?
- `equals()`
- `hasCode()` 

Code:
```
public void testEquality() {
  assertTrue(new Dollar(5).)
}
```

## 4 Privacy

## 5 Franc-ly Speaking

## 6 Equality for All, Redux

## 7 Apples and Oranges

## 8 Making Objects

[1]:https://stanislaw.github.io/2016/01/25/notes-on-test-driven-development-by-example-by-kent-beck.html
