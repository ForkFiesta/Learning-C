# Notes on Hashing

## Notes from [Lecture 8: Hashing with Chaining](https://www.youtube.com/watch?v=0M_kIqhwbFo&list=PLUl4u3cNGP61Oq3tWYp6V_F-5jb5L2iHb&index=9)

Dictionary: an abstract data type (ADT)

- Maintain set of items each with a key
  - Insert(item): overwrites any existing key
  - Delete(item)
  - Search(Key) : Returns item with the given key or report it is not in the table
    - Only interested on whether the key exists or not

**All operations above are O(1) with the only assumption that your keys are integers**

In Python: this is the `dict` structure.

- `D[key]` ~ search
- `D[Key] = val` ~ insert
- `del D[key]` ~ delete

an item in python is a pair, where `item = (key, value)`

### Motivation: Why is this important

- Doctdist
  - can quickly find common words between two documents.
- Databases:
  - There are two types of databases in the world:
    1. Those that use hashing.
    2. Those that use search trees.
- Modern Dictionaries ie meriam webster
- Spellcheck
  - Quickly finds proper spelling of word. If word is mispelled. Iterate through all characters of words and look for closest resemblance in dictionary.
- Compilers & intrepeters
  - Whenever you type a variable name it uses hashing to store all of your variables
- Network router

  - Maintains a dictionary of all the devices that are connected to it

- Less obvious applications of hashing
  - substring search
  - string commonalities
  - file & directory syncronization
  - cyptography

### Simple approach:

- **Direct access table:**

  - Store items m in array indexed by key
  - Every key that I want to use you just store the value at the corresponding position
  - Keys that aren't used will leave as null or some other character representing null

  Cons of Above:

  - Keys may not be integers.
  - Can be a gigantic memory hog.

  #### Solution to Con #1: Prehash

  - Maps keys to non-negative integers.
  - In theory, keys are finite and discrete (string of bits)
  - in Python, `hash(x)` is the prehash of X
    - if you give it an integer it returns an integer
    - if you give it a string it returns an integer but there are issues.
      - `hash('\0B')` = `hash('\0\0C')` = `64` ~ unideal collisions
      - ideally : hash(x) = hash(y)
    - If you create a custom object you can use `__hash__` to modify the default behavior for hashing on that object. The default being it uses the phyiscal address of memory where that object is stored, and as long as that object isn't moving around this is pretty good because no two items occupy the same space in memory.
    - Prehash really should not change or you won't be able to retrieve the original item

#### Solution to Con #1: Hashing

- Germanically, it's like _hatchet_. You cut up the key into a bunch of different pieces

- > reduce universe $\mu$ of all keys (integers) down to reasonable size m for table -> to possible keys of 0 to m-1. $h : \mu$ -> $\{0,1, ...m-1\}$ and the hash function needs to know what the table size is.
- > idea: $m = \theta(n)$ : The size of the table is proportional to the size of the dictionary.
- But now collisions are possible where two different keys may correspond to a single space in the table. where $h(k_i) = h(k_j)$ but $k_i \neq k_j$

### Chaining - a solution to dealing with Chaining

Chaining : linked list of colliding elements in each slot of hash table

- a slot in the table will be a pointer to the first item and if more than 1 item correspond to that slot, then that first item will have a pointer to the next and so forth
- Empty slots will have a null pointer

Worst Case: $\theta (n)$

### Simple Uniform Hashing

- false assumption convenient for analysis
- That is, that each key is equally likely to be hashed to any slot of the table independent of where other keys hashing.
  - we need uniformity and independence
  - **But this really can't be true** but if it were we can prove that hashing with chaining can give us $\theta(n)$

#### Analysis of Above

- expected length of chain for n keys, m slots is $n/m = \alpha =$ load factor
- = $\theta(1)$ if $m=\theta(n)$
- running time = $O (1 + \:length\, of\, chain) = O(1 + \alpha)$

### Hash Functions

- 3 hash functions - 2 of which are practical and 1 is theoretically good.
  1. Division method:
     - $h(k)\:=\: k\, mod\, m$
       - lots of situations where this is bad, but in practice it's pretty good if m is prime and it's not really close to $m^2$ or $m^10$.
  2. Multiplication method:
     - $h(k) = [(a*k)\: mod\,2^w]\,>>\,(w-r)$
