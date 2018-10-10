def search4vowels(phrase:str) ->set:
    """Return any vowels found in asupplied phrase."""
    vowels=set('aeiou')
    return vowels.intersection(set(phrase))

def search4letters(phrase:str,letters:str='aeiou') ->set:
    #上面提供默认值aeiou
    """Return a set of the 'letters' found in phrase."""
    return set(letters).intersection(set(phrase))

print(search4letters('lifurong','artt'))
print(search4letters('wangqin'))