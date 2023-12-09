cout<<"\nThe map gquiz2 after"
    <<"\nassign from gquiz1 is: \n";
cout<<"\tKey\tElement\n";
for(itr = gquiz2.begin(); int != gquiz2.end(); ++itr){
    cout<<'\t'<< itr->first
    cout<<'\t'<< itr->second << '\n';
}
cout << endl;

cout<<endl;

cout<<"\ngquiz2 after removal of"
    "elements less than key=3 : \n";
cout<<"\tKEY\tELEMENT\n";
gquiz2.erase(gquiz.begin(), gquiz2.find(3));
for(itr = gquiz2.begin(); itr != gquiz2.end(); ++itr){
    count<<'\t'<< itr->first
    count<<'\t'<< itr->second <<'\n';
}