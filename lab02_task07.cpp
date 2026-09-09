#include<iostream>
using namespace std;

//row - playlist 
//col - diff num of tracks

class PlaylistManager{
	int** customPlaylists;
	int* playlistCapacities;
	int playlistsCount;
	
	public:
	PlaylistManager(int p){
		playlistsCount = p;
		playlistCapacities = new int[playlistsCount];
		
		customPlaylists = new int* [playlistsCount];
		for(int i = 0; i < playlistsCount ; i++){
			cout<<"Enter number of tracks to add in playlist "<<i+1<<": "<<endl;
			cin>>playlistCapacities[i];
			customPlaylists[i] = new int [playlistCapacities[i]];
		}
		for(int i=0; i<playlistsCount; i++){
			cout<<"Enter track IDs for playlist "<<i+1<<": "<<endl;
		for(int j =0; j<playlistCapacities[i]; j++){
			cin>>customPlaylists[i][j];
		}
	}
}
	
	void addMoreTracksToAPlaylist(int playlist){
		if(playlist<=0 || playlist>playlistsCount){
			cout<<"playlist out of bound"<<endl;
			return;
		}
		int count;
		cout<<"How many more tracks do you want to add to playlist "<<playlist<<endl;
		cin>>count;
		
		playlistCapacities[playlist-1] += count;
		int* temp = new int[playlistCapacities[playlist-1]];
		
		for(int j=0; j<playlistCapacities[playlist-1]-count; j++){
		    temp[j] = customPlaylists[playlist-1][j];
	    }
	    
            delete [] customPlaylists[playlist-1];
    

		customPlaylists[playlist-1]= temp;

		for(int i = playlistCapacities[playlist-1] - count;  i<playlistCapacities[playlist-1]; i++){
			cout<<"Enter new track IDs: ";
			cin>>customPlaylists[playlist-1][i];
		}
		
	}
	
	void addANewPlaylist(int tracks){
		playlistsCount++;
		int* tempCapacities = new int[playlistsCount];
		
		for(int i =0; i<playlistsCount-1 ; i++){
			tempCapacities[i] = playlistCapacities[i];
		}
		tempCapacities[playlistsCount-1] = tracks;
		
		delete [] playlistCapacities;
		playlistCapacities = tempCapacities;
		
		int** temp = new int*[playlistsCount];
		for(int i = 0; i<playlistsCount; i++){
			temp[i]= new int[playlistCapacities[i]];
		}
		
		for(int i=0; i<playlistsCount-1; i++){
			for(int j=0; j<playlistCapacities[i]; j++){
				temp[i][j] = customPlaylists[i][j];
			}
		}
		
		for(int i = 0; i<tracks; i++){
			cout<<"Enter track IDs for your new playlist: ";
			cin>>temp[playlistsCount-1][i]; 
		}
		for(int i = 0; i<playlistsCount-1; i++){
		    delete [] customPlaylists[i];
		}
		delete [] customPlaylists;
		customPlaylists =temp;
	}
	
	void displayPlaylists(){
		cout<<"\nDISPLAYING PLAYLISTS:\n";
		for(int i = 0; i<playlistsCount; i++){
			for(int j=0; j<playlistCapacities[i]; j++){
				cout<<customPlaylists[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
	PlaylistManager(const PlaylistManager& other){
		playlistsCount = other.playlistsCount;
		playlistCapacities = new int[playlistsCount];
		
		for(int i = 0 ; i<playlistsCount; i++){
			playlistCapacities[i] = other.playlistCapacities[i];
		}
		
		customPlaylists = new int* [playlistsCount];
		for(int i = 0; i < playlistsCount ; i++){
			customPlaylists[i] = new int[playlistCapacities[i]];
		}
		
		for(int i=0; i<playlistsCount; i++){
			for(int j=0; j<playlistCapacities[i]; j++){
				customPlaylists[i][j] = other.customPlaylists[i][j];
			}
		}
	}
	
	void PlaySong(int playlist, int track){
		if(playlist<=0 || playlist>playlistsCount){
			cout<<"Playlists out of bound";
			return;
		}
		if(track <=0 || track>playlistCapacities[playlist-1]){
			cout<<"Track out of bound";
			return;
		}
		
		cout<<"Playing song from playlist "<<playlist<<" track "<<track<<": ";
		cout<<customPlaylists[playlist-1][track-1]<<endl;
	}
	
	~PlaylistManager(){
		delete [] playlistCapacities;
		for(int i = 0; i < playlistsCount ; i++){
			delete [] customPlaylists[i];
		}
		delete[] customPlaylists;
	}
};

int main(){
    
    cout<<"3 playlists created for p1\n";
    PlaylistManager p1(3);
    p1.displayPlaylists();
    cout<<"\nADDING MORE TRACKS TO PLAYLIST 1\n";
    p1.addMoreTracksToAPlaylist(1);
    p1.displayPlaylists();
    cout<<"\nADDING A NEW PLAYLIST WITH 3 TRACKS\n";
    p1.addANewPlaylist(3);
    p1.displayPlaylists();
    cout<<"\nDEEP COPY CONSTRUCTOR CALLED for p2\n";
    PlaylistManager p2(p1);
    cout<<"\nADDING MORE TRACKS TO PLAYLIST 2 in p2\n";
    p2.addMoreTracksToAPlaylist(2);
    cout<<"\n\nPLAYLIST 1:\n";
    p1.displayPlaylists();
    cout<<"\n\nPLAYLIST 2:\n";
    p2.displayPlaylists();

    cout<<"PLAYING SONGS: \n";
    p1.PlaySong(1, 2);
    p1.PlaySong(5, 1);    //playlist out of bound
    p1.PlaySong(2, 10);   //track out of bound

	return 0;
}

