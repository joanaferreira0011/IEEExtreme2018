var readline = require('readline');

function sortNumber(a,b) {
    return b-a;
}

function sortArray(a,b) {
    if (a.hindex == b.hindex) {
        if (b.name < a.name) {
            return 1;
        }
    }
    return b.hindex - a.hindex;
}

function main() {
    // write your code here.
    // call functions `nextString`, `nextFloat` and `nextInt` 
    // to read the next token of input (ignoring whitespace)
    // Alternatively, you can create your own input parser functions
    // use console.log() to write to stdout

    var c = nextInt();
    
    var authors = {};
    for (let j = 0; j < c; j++) {
        var article = JSON.parse(nextLine());
        var article_auths = article.authors.authors;
        var article_citations = article.citing_paper_count;
        
        for (let k = 0; k < article_auths.length; k++) {
            var author_name = article_auths[k]["full_name"];
            if (!authors[author_name]) {
                let newAuthor = {
                    "articleCount" : 1,
                    "citations" : [article_citations]
                }
                authors[author_name] = newAuthor;
            } else {
                authors[author_name]["articleCount"] ++;
                authors[author_name]["citations"].push(article_citations);
            }
        }
        
    }
    for (let name in authors) {
        authors[name].citations.sort(sortNumber);
    }
    
    var info = [];
    for (let name in authors) {
        if (authors[name].citations.length == 0) {
            let newele = {
                "name" : name,
                "hindex" : 0
            }
            let repeated = false;
            for (h = 0; h < info.length; h++) {
                if (info[h].name == newele.name)
                repeated = true;
            }
            if (!repeated)
                info.push(newele);
            continue;
        }
        var hindex;
        var foundh = false;
        for (hindex = authors[name].citations.length; hindex >= 0; hindex--) {
            var aboveh = 0;
            for (var m = 0; m < authors[name].citations.length; m++) {
                if (authors[name].citations[m] >= hindex) {
                    aboveh++;
                } else {
                    if (aboveh >= hindex) {
                        let newele = {
                            "name" : name,
                            "hindex" : hindex
                        }
                        let repeated = false;
                        for (h = 0; h < info.length; h++) {
                            if (info[h].name == newele.name)
                            repeated = true;
                        }
                        if (!repeated)
                            info.push(newele);
                        foundh = true;
                        break;
                    }
                    else {
                        break;
                    }
                }
            }
            if (foundh) break;
            
            if (aboveh >= hindex) {
                let newele = {
                    "name" : name,
                    "hindex" : hindex
                }
                let repeated = false;
                for (h = 0; h < info.length; h++) {
                    if (info[h].name == newele.name)
                    repeated = true;
                }
                if (!repeated)
                    info.push(newele);
                break;
            }
        }
    }
    
    info.sort(sortArray);
    
    for (var n = 0; n < info.length; n++) {
        console.log(info[n].name + " " + info[n].hindex + '\n');
    }
}

// default parsers for JS.
function nextInt() {
    return parseInt(nextString());
}

function nextFloat() {
    return parseFloat(nextString());
}

function nextString() {
    var next_string = "";
    clearWhitespaces();
    while (input_cursor < input_stdin.length && !isWhitespace(input_stdin[input_cursor])) {
        next_string += input_stdin[input_cursor];
        input_cursor += 1;
    }
    return next_string;
}

function nextLine() {
    var next_string = "";
    clearWhitespaces();
    while (input_cursor < input_stdin.length && input_stdin[input_cursor] !='\n') {
        next_string += input_stdin[input_cursor];
        input_cursor += 1;
    }
    return next_string;
}

function nextChar() {
    clearWhitespaces();
    if (input_cursor < input_stdin.length) {
        return input_stdin[input_cursor++];
    } else {
        return '\0';
    }
}

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_cursor = 0;
process.stdin.on('data', function (data) { input_stdin += data; });
process.stdin.on('end', function () { main(); });

function isWhitespace(character) {
    return ' \t\n\r\v'.indexOf(character) > -1;
}

function clearWhitespaces() {
    while (input_cursor < input_stdin.length && isWhitespace(input_stdin[input_cursor])) {
        // ignore the next whitespace character
        input_cursor += 1;
    }  
}