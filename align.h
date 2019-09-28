int align(char *ref, char *query, int m, int ms, int g){
  //Calculate rows (i) and columns (j) for the matrix
  int rows, cols;
  rows = seqLen(ref) + 1;
  cols = seqLen(query) + 1;

  int M[rows][cols]; //Initialize the scoring matrix

  int i, j; //Initialize i and j

  //1. INITIALIZATION (of the score matrix)
  //the first row and first column of the matrix are filled by introducing gaps
  for (i = 0; i < rows; i ++){
    M[i][0] = g*i;
  }
  for (j = 0; j < cols; j ++){
    M[0][j] = g*j;
  }

  //2. SCORING
  for (i = 1; i < rows; i ++){
    for (j = 1; j < cols; j ++){
      int matchMismatch = 0;
      //S(Xi,Yj) = {m if Xi==Yj, ms if Xi!=Yj}
      if (ref[j-1] == query[i-1]){
        matchMismatch = M[i-1][j-1] + m; //if it is a match, use ms (argv[3])
      }

      else{
        matchMismatch = M[i-1][j-1] + ms; //if it is a mismatch, use m (argv[4])
      }
      int deletion = M[i-1][j] + g; //if there's a gap in the ref sequence
      int insertion = M[i][j-1] + g; //if there's a gap in the query sequence
      int maxScore = max(matchMismatch, deletion, insertion);

      M[i][j] = maxScore;
      printf("M[%d][%d] = %d\n", i, j, M[i][j]);
    }
  }
return 0;
}
