  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 139;
      section.data(139)  = dumData; %prealloc
      
	  ;% rtP.B
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.BBT_inv
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% rtP.J
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 72;
	
	  ;% rtP.Ka
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 81;
	
	  ;% rtP.Kd
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 82;
	
	  ;% rtP.Kf
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 83;
	
	  ;% rtP.Kt
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 84;
	
	  ;% rtP.L
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 85;
	
	  ;% rtP.M
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 86;
	
	  ;% rtP.Q
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 87;
	
	  ;% rtP.R
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 123;
	
	  ;% rtP.RM_1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 159;
	
	  ;% rtP.alpha_P
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 175;
	
	  ;% rtP.alpha_Slid
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 176;
	
	  ;% rtP.alpha_V
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 177;
	
	  ;% rtP.gamma_0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 178;
	
	  ;% rtP.gamma_1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 214;
	
	  ;% rtP.ge
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 250;
	
	  ;% rtP.k1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 251;
	
	  ;% rtP.k1o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 252;
	
	  ;% rtP.k2
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 253;
	
	  ;% rtP.k2o
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 254;
	
	  ;% rtP.rho_0
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 255;
	
	  ;% rtP.rho_1
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 256;
	
	  ;% rtP.Gain2_Gain
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 257;
	
	  ;% rtP.Gain2_Gain_c2uyk0coml
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 258;
	
	  ;% rtP.Integrator_IC
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 259;
	
	  ;% rtP.TransportDelay_Delay
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 271;
	
	  ;% rtP.TransportDelay_InitOutput
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 272;
	
	  ;% rtP.TransportDelay1_Delay
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 273;
	
	  ;% rtP.TransportDelay1_InitOutput
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 274;
	
	  ;% rtP.TransportDelay2_Delay
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 275;
	
	  ;% rtP.TransportDelay2_InitOutput
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 276;
	
	  ;% rtP.Integrator2_IC
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 277;
	
	  ;% rtP.Integrator_IC_au2dj45vgj
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 279;
	
	  ;% rtP.Integrator1_IC
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 291;
	
	  ;% rtP.Integrator_IC_bzpo215sgo
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 293;
	
	  ;% rtP.Integrator1_IC_kniptj1kxt
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 294;
	
	  ;% rtP.Gain_Gain
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 295;
	
	  ;% rtP.Integrator3_IC
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 296;
	
	  ;% rtP.Memory_InitialCondition
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 302;
	
	  ;% rtP.Integrator_IC_kjcjwivfdd
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 308;
	
	  ;% rtP.Integrator1_IC_bfgbvvrang
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 314;
	
	  ;% rtP.Integrator1_IC_etk5iarzoa
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 320;
	
	  ;% rtP.Integrator_IC_d53cezkjnk
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 356;
	
	  ;% rtP.Integrator2_IC_milw2qy4e1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 392;
	
	  ;% rtP.Integrator3_IC_mvcbk0lpqx
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 398;
	
	  ;% rtP.Memory_InitialCondition_ltjalipc0r
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 404;
	
	  ;% rtP.Integrator_IC_i2crhtqu0w
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 410;
	
	  ;% rtP.Integrator1_IC_og2211l4hi
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 416;
	
	  ;% rtP.Integrator1_IC_ea4j2itlpr
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 422;
	
	  ;% rtP.Integrator_IC_lijhdzhcao
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 458;
	
	  ;% rtP.Integrator2_IC_eshmddcula
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 494;
	
	  ;% rtP.Memory_InitialCondition_cltcggngaa
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 500;
	
	  ;% rtP.Gain_Gain_pqv5poqtm5
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 512;
	
	  ;% rtP.SineWave_Amp
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 513;
	
	  ;% rtP.SineWave_Bias
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 514;
	
	  ;% rtP.SineWave_Freq
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 515;
	
	  ;% rtP.SineWave_Phase
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 516;
	
	  ;% rtP.SineWave1_Amp
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 517;
	
	  ;% rtP.SineWave1_Bias
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 518;
	
	  ;% rtP.SineWave1_Freq
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 519;
	
	  ;% rtP.SineWave1_Phase
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 520;
	
	  ;% rtP.Constant_Value
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 521;
	
	  ;% rtP.TransferFcn2_A
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 522;
	
	  ;% rtP.TransferFcn2_C
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 523;
	
	  ;% rtP.Constant1_Value
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 524;
	
	  ;% rtP.TransferFcn3_A
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 525;
	
	  ;% rtP.TransferFcn3_C
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 526;
	
	  ;% rtP.Constant2_Value
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 527;
	
	  ;% rtP.TransferFcn1_A
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 528;
	
	  ;% rtP.TransferFcn1_C
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 529;
	
	  ;% rtP.FromWs_Time0
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 530;
	
	  ;% rtP.FromWs_Data0
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 536;
	
	  ;% rtP.TransferFcn_A
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 542;
	
	  ;% rtP.TransferFcn_C
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 543;
	
	  ;% rtP.FromWorkspace_Time0
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 544;
	
	  ;% rtP.FromWorkspace_Data0
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 1145;
	
	  ;% rtP.Gain_Gain_bttrwertaz
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 1746;
	
	  ;% rtP.FromWorkspace1_Time0
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 1747;
	
	  ;% rtP.FromWorkspace1_Data0
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 2348;
	
	  ;% rtP.Gain1_Gain
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 2949;
	
	  ;% rtP.FromWorkspace3_Time0
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 2950;
	
	  ;% rtP.FromWorkspace3_Data0
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 3551;
	
	  ;% rtP.DesiredPosition4_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 4152;
	
	  ;% rtP.Switch_Threshold
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 4153;
	
	  ;% rtP.Memory_InitialCondition_ihnyqfqp54
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 4154;
	
	  ;% rtP.Integrator1_IC_cysw5lmkvd
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 4155;
	
	  ;% rtP.Gain_Gain_mauqb2akec
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 4156;
	
	  ;% rtP.Integrator_IC_mdtcnu4jbd
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 4157;
	
	  ;% rtP.TransportDelay_Delay_mrtq4yly2u
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 4158;
	
	  ;% rtP.TransportDelay_InitOutput_bw2s5ogtcl
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 4159;
	
	  ;% rtP.Gain1_Gain_lwvfyvhuab
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 4160;
	
	  ;% rtP.TransportDelay1_Delay_l2osw0ocdi
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 4161;
	
	  ;% rtP.TransportDelay1_InitOutput_ctmwtl3hbr
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 4162;
	
	  ;% rtP.Gain2_Gain_gy0kebd21j
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 4163;
	
	  ;% rtP.TransportDelay2_Delay_dxj4qf2s24
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 4164;
	
	  ;% rtP.TransportDelay2_InitOutput_ddz2iqhful
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 4165;
	
	  ;% rtP.Gain3_Gain
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 4166;
	
	  ;% rtP.Integrator3_IC_nyxzwevmz0
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 4167;
	
	  ;% rtP.Memory_InitialCondition_ogj5j113sv
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 4173;
	
	  ;% rtP.Integrator_IC_i3pypvjz4s
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 4179;
	
	  ;% rtP.Integrator1_IC_lyrbs4mryj
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 4185;
	
	  ;% rtP.Integrator1_IC_aondaic4tn
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 4191;
	
	  ;% rtP.Integrator_IC_dn1v3y4i5t
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 4227;
	
	  ;% rtP.Integrator2_IC_eq0rr2lar5
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 4263;
	
	  ;% rtP.Integrator3_IC_oqmkotgcvb
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 4269;
	
	  ;% rtP.Memory_InitialCondition_dew5rdr00k
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 4275;
	
	  ;% rtP.Integrator_IC_ow1ezrd30j
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 4281;
	
	  ;% rtP.Integrator1_IC_l4ui1a44g1
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 4287;
	
	  ;% rtP.Integrator1_IC_dwmkl32mdn
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 4293;
	
	  ;% rtP.Integrator_IC_puc2fkypqe
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 4329;
	
	  ;% rtP.Integrator2_IC_pkgbdnqjyc
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 4365;
	
	  ;% rtP.Gain_Gain_pjv0l5nu25
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 4371;
	
	  ;% rtP.SineWave_Amp_cqusaijwz1
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 4372;
	
	  ;% rtP.SineWave_Bias_dhkcw5madh
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 4373;
	
	  ;% rtP.SineWave_Freq_hkeiim1l54
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 4374;
	
	  ;% rtP.SineWave_Phase_atfet5pyf2
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 4375;
	
	  ;% rtP.SineWave1_Amp_mdrsfgbaur
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 4376;
	
	  ;% rtP.SineWave1_Bias_eubjrqq2u4
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 4377;
	
	  ;% rtP.SineWave1_Freq_ekxuh2oqwg
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 4378;
	
	  ;% rtP.SineWave1_Phase_pvy3avqa4x
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 4379;
	
	  ;% rtP.Constant_Value_f3fl4m3lns
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 4380;
	
	  ;% rtP.TransferFcn2_A_a0oyqusjcz
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 4381;
	
	  ;% rtP.TransferFcn2_C_dmkbndw1jb
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 4382;
	
	  ;% rtP.Constant1_Value_bfcgyn3zal
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 4383;
	
	  ;% rtP.TransferFcn3_A_luwp2lluol
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 4384;
	
	  ;% rtP.TransferFcn3_C_bgvnqgidnw
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 4385;
	
	  ;% rtP.Constant2_Value_imre1apqn2
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 4386;
	
	  ;% rtP.TransferFcn1_A_bowexjz0op
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 4387;
	
	  ;% rtP.TransferFcn1_C_gbzdyi5fsz
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 4388;
	
	  ;% rtP.FromWs_Time0_dvongqu3oc
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 4389;
	
	  ;% rtP.FromWs_Data0_bk0ugsj5dc
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 4395;
	
	  ;% rtP.TransferFcn_A_opc1nfp3z4
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 4401;
	
	  ;% rtP.TransferFcn_C_etz5z3jsj3
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 4402;
	
	  ;% rtP.DesiredPosition4_Value_izm2550djd
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 4403;
	
	  ;% rtP.FromWorkspace3_Time0_arirwmivf2
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 4404;
	
	  ;% rtP.FromWorkspace3_Data0_glaft0xfxw
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 5005;
	
	  ;% rtP.Switch_Threshold_isku2iufnm
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 5606;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 39;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% rtB.ivgrkuetfr
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.jx10qz0y32
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 12;
	
	  ;% rtB.mgwl4qchuz
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 13;
	
	  ;% rtB.g4uzmogaho
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 14;
	
	  ;% rtB.iolwo3nnoi
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 15;
	
	  ;% rtB.etvvsvbtr0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 18;
	
	  ;% rtB.fp1jf5ytc0
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 30;
	
	  ;% rtB.lxmuzwnnxk
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 32;
	
	  ;% rtB.cn0dzpfmb5
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 44;
	
	  ;% rtB.dlk22jmuti
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 46;
	
	  ;% rtB.f5ibyqhnm5
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 48;
	
	  ;% rtB.ofqfdlsgnm
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 50;
	
	  ;% rtB.ozsyjbt0zf
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 56;
	
	  ;% rtB.l2okftp1nu
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 62;
	
	  ;% rtB.jfhxiyyt2e
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 63;
	
	  ;% rtB.m45fkguer0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 64;
	
	  ;% rtB.hzr1dfuf5l
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 65;
	
	  ;% rtB.m3xmkbwv00
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 66;
	
	  ;% rtB.bzd1lyzgz1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 67;
	
	  ;% rtB.lgrmzrtnoa
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 68;
	
	  ;% rtB.nnr1ahifvl
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 69;
	
	  ;% rtB.ndl3k25chw
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 70;
	
	  ;% rtB.gslpjnsh5g
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 73;
	
	  ;% rtB.fb2enyqb0z
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 75;
	
	  ;% rtB.f5j3k1cgkz
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 77;
	
	  ;% rtB.ejv5n5dh4j
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 78;
	
	  ;% rtB.gol00soltl
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 79;
	
	  ;% rtB.edxclkusat
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 80;
	
	  ;% rtB.bu5fouv53z
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 83;
	
	  ;% rtB.ftcjn2x21e
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 89;
	
	  ;% rtB.e2xua1vi2a
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 95;
	
	  ;% rtB.h1dldewdlg
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 96;
	
	  ;% rtB.e43dgc14sk
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 97;
	
	  ;% rtB.kryicu302t
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 98;
	
	  ;% rtB.jz5340fyqc
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 99;
	
	  ;% rtB.mztx0ubroi
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 100;
	
	  ;% rtB.o3szt5ur1k
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 101;
	
	  ;% rtB.c3o3xjf5wt
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 102;
	
	  ;% rtB.liy3ccyuzf
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 104;
	
	  ;% rtB.nof2skbwsq
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 106;
	
	  ;% rtB.pc3poziqbx
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 118;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.hqeceb1qj5.o5vw3qgp1n
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.hc5s13aofb.bscgwtwcot
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.hc5s13aofb.idzmiix4px
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtB.hc5s13aofb.hjeyr5gjr3
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.iz2vhx1had.dy01b2bgnp
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.fch5gmq0mk.llum1d4imd
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.m4nweffg3k.c0eitivnzv
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.lqm3tkmrj0.bkxow1zaxw
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.drmxackmon.g3f2ipoicp
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.evmbjc0b4d.agvkxpaya3
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.ddjji0axxh.b5v3smwxxf
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ddjji0axxh.nbc5e1aa4y
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtB.ddjji0axxh.kncnn35ehq
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dbfm2fggcf.dy01b2bgnp
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.n5z0v3jy3r.agvkxpaya3
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dwgomjumxz.llum1d4imd
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.dwyanlti1g.c0eitivnzv
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.kblwc120uj.bkxow1zaxw
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.cnusct4inu.g3f2ipoicp
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.crvoapndv2.h4nyij0txf
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtB.esmlujbtbz.ispj2sto2a
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.esmlujbtbz.a3fw5udt1f
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.p4ycag1e5s.pccs3jrnen
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.bmakjzspmx.hfqvj0omua
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ghv0odgskz.pccs3jrnen
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.kscttm531o.hfqvj0omua
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.oxu2odnx00.o5vw3qgp1n
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(23) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.ne34mblrux.bscgwtwcot
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.ne34mblrux.idzmiix4px
	  section.data(2).logicalSrcIdx = 69;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtB.ne34mblrux.hjeyr5gjr3
	  section.data(3).logicalSrcIdx = 70;
	  section.data(3).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.imeubyypoc.dy01b2bgnp
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.lfdnfksqrv.llum1d4imd
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.pmwvgwx3i3.c0eitivnzv
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.kwzvd2zz43.bkxow1zaxw
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.o3xr450ufq.g3f2ipoicp
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.porpvvdkpb.agvkxpaya3
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(30) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% rtB.pcmu2rnoht.b5v3smwxxf
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.pcmu2rnoht.nbc5e1aa4y
	  section.data(2).logicalSrcIdx = 78;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtB.pcmu2rnoht.kncnn35ehq
	  section.data(3).logicalSrcIdx = 79;
	  section.data(3).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.lfuuj0xy5s.dy01b2bgnp
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.duudknct5v.agvkxpaya3
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.gxc0uqkvgw.llum1d4imd
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.kwvmxh0kpo.c0eitivnzv
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ccm3czt3ct.bkxow1zaxw
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.himcwdjdya.g3f2ipoicp
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(37) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.opcrukpa55.h4nyij0txf
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(38) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtB.jqsclsqnve.ispj2sto2a
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.jqsclsqnve.a3fw5udt1f
	  section.data(2).logicalSrcIdx = 88;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(39) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 39;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% rtDW.ksudpu4fau
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.knl5mpgsrd
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtDW.g0rrq0apzs
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtDW.aauqgom500
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% rtDW.hkoqfk3gpr
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 36;
	
	  ;% rtDW.l3xxd05qkk
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 42;
	
	  ;% rtDW.jy3xilpi33.modelTStart
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 48;
	
	  ;% rtDW.nwftmqpxni.modelTStart
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 49;
	
	  ;% rtDW.ftfqvcynyd.modelTStart
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 50;
	
	  ;% rtDW.b1ge0hee1v.modelTStart
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 51;
	
	  ;% rtDW.b50ygqfxun.modelTStart
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 52;
	
	  ;% rtDW.dkp2gvli2p.modelTStart
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 53;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 41;
      section.data(41)  = dumData; %prealloc
      
	  ;% rtDW.eh14jxkpry.LoggedData
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ftwma3npp0.TUbufferPtrs
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.emkvxxu5kw.TUbufferPtrs
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 3;
	
	  ;% rtDW.ikb4keconr.TUbufferPtrs
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 5;
	
	  ;% rtDW.jhpavj442h.LoggedData
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 7;
	
	  ;% rtDW.idznnk4ivb.LoggedData
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtDW.dbrb4job1l.LoggedData
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtDW.pw1fr2aeqv.LoggedData
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 10;
	
	  ;% rtDW.jon4oo2kgm.LoggedData
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtDW.bpfscmb3y2.LoggedData
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtDW.d2eq1qne2f.LoggedData
	  section.data(11).logicalSrcIdx = 22;
	  section.data(11).dtTransOffset = 13;
	
	  ;% rtDW.j3huo2xvys.LoggedData
	  section.data(12).logicalSrcIdx = 23;
	  section.data(12).dtTransOffset = 14;
	
	  ;% rtDW.p4sgzkj20f.LoggedData
	  section.data(13).logicalSrcIdx = 24;
	  section.data(13).dtTransOffset = 15;
	
	  ;% rtDW.dvrntr3mzm.LoggedData
	  section.data(14).logicalSrcIdx = 25;
	  section.data(14).dtTransOffset = 16;
	
	  ;% rtDW.pvuv30ujfg.TimePtr
	  section.data(15).logicalSrcIdx = 26;
	  section.data(15).dtTransOffset = 17;
	
	  ;% rtDW.df5c2nfbgg.TimePtr
	  section.data(16).logicalSrcIdx = 27;
	  section.data(16).dtTransOffset = 18;
	
	  ;% rtDW.n1ay2gmo0o.TimePtr
	  section.data(17).logicalSrcIdx = 28;
	  section.data(17).dtTransOffset = 19;
	
	  ;% rtDW.pjpkrcvyhb.TimePtr
	  section.data(18).logicalSrcIdx = 29;
	  section.data(18).dtTransOffset = 20;
	
	  ;% rtDW.g4djpfw4yq.LoggedData
	  section.data(19).logicalSrcIdx = 30;
	  section.data(19).dtTransOffset = 21;
	
	  ;% rtDW.kwz4psqkit.LoggedData
	  section.data(20).logicalSrcIdx = 31;
	  section.data(20).dtTransOffset = 24;
	
	  ;% rtDW.eu2d5e54n4.LoggedData
	  section.data(21).logicalSrcIdx = 32;
	  section.data(21).dtTransOffset = 26;
	
	  ;% rtDW.nvpfdb2hmo.LoggedData
	  section.data(22).logicalSrcIdx = 33;
	  section.data(22).dtTransOffset = 27;
	
	  ;% rtDW.earmeghfsf.LoggedData
	  section.data(23).logicalSrcIdx = 34;
	  section.data(23).dtTransOffset = 28;
	
	  ;% rtDW.bb1yh35qnp.LoggedData
	  section.data(24).logicalSrcIdx = 35;
	  section.data(24).dtTransOffset = 29;
	
	  ;% rtDW.l4liyn0zrr.LoggedData
	  section.data(25).logicalSrcIdx = 36;
	  section.data(25).dtTransOffset = 30;
	
	  ;% rtDW.hjrvfzz0ar.LoggedData
	  section.data(26).logicalSrcIdx = 37;
	  section.data(26).dtTransOffset = 31;
	
	  ;% rtDW.ekl3igs5tb.LoggedData
	  section.data(27).logicalSrcIdx = 38;
	  section.data(27).dtTransOffset = 32;
	
	  ;% rtDW.o3rktodv2z.LoggedData
	  section.data(28).logicalSrcIdx = 39;
	  section.data(28).dtTransOffset = 33;
	
	  ;% rtDW.o1d2fjrwn1.LoggedData
	  section.data(29).logicalSrcIdx = 40;
	  section.data(29).dtTransOffset = 34;
	
	  ;% rtDW.fzezo0tjjd.TUbufferPtrs
	  section.data(30).logicalSrcIdx = 41;
	  section.data(30).dtTransOffset = 36;
	
	  ;% rtDW.nashv3gsf0.TUbufferPtrs
	  section.data(31).logicalSrcIdx = 42;
	  section.data(31).dtTransOffset = 38;
	
	  ;% rtDW.lwvvduadv2.TUbufferPtrs
	  section.data(32).logicalSrcIdx = 43;
	  section.data(32).dtTransOffset = 40;
	
	  ;% rtDW.pskx1pep5n.LoggedData
	  section.data(33).logicalSrcIdx = 44;
	  section.data(33).dtTransOffset = 42;
	
	  ;% rtDW.jozpq0htbq.LoggedData
	  section.data(34).logicalSrcIdx = 45;
	  section.data(34).dtTransOffset = 43;
	
	  ;% rtDW.msfllwrq11.LoggedData
	  section.data(35).logicalSrcIdx = 46;
	  section.data(35).dtTransOffset = 44;
	
	  ;% rtDW.lkmyovzpp0.LoggedData
	  section.data(36).logicalSrcIdx = 47;
	  section.data(36).dtTransOffset = 45;
	
	  ;% rtDW.l2kwb1e0rl.LoggedData
	  section.data(37).logicalSrcIdx = 48;
	  section.data(37).dtTransOffset = 46;
	
	  ;% rtDW.fntjtmi5ec.LoggedData
	  section.data(38).logicalSrcIdx = 49;
	  section.data(38).dtTransOffset = 47;
	
	  ;% rtDW.j2g15onptf.LoggedData
	  section.data(39).logicalSrcIdx = 50;
	  section.data(39).dtTransOffset = 48;
	
	  ;% rtDW.gq3i5ctc0q.TimePtr
	  section.data(40).logicalSrcIdx = 51;
	  section.data(40).dtTransOffset = 49;
	
	  ;% rtDW.lp5ova0wqa.TimePtr
	  section.data(41).logicalSrcIdx = 52;
	  section.data(41).dtTransOffset = 50;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% rtDW.b2wnsubu1l.Tail
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.lxjlqbqfhh.Tail
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.fsebzkjcav.Tail
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.hn2dovhdxs
	  section.data(4).logicalSrcIdx = 56;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.ldylaj45rj
	  section.data(5).logicalSrcIdx = 57;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtDW.edcbzf0yn0.PrevIndex
	  section.data(6).logicalSrcIdx = 58;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtDW.pnnerq5f2i.PrevIndex
	  section.data(7).logicalSrcIdx = 59;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtDW.exnemuedsi.PrevIndex
	  section.data(8).logicalSrcIdx = 60;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtDW.ayaahgomzc.PrevIndex
	  section.data(9).logicalSrcIdx = 61;
	  section.data(9).dtTransOffset = 9;
	
	  ;% rtDW.autydayctb.Tail
	  section.data(10).logicalSrcIdx = 62;
	  section.data(10).dtTransOffset = 10;
	
	  ;% rtDW.cctjnquf0p.Tail
	  section.data(11).logicalSrcIdx = 63;
	  section.data(11).dtTransOffset = 11;
	
	  ;% rtDW.npknkce1d5.Tail
	  section.data(12).logicalSrcIdx = 64;
	  section.data(12).dtTransOffset = 12;
	
	  ;% rtDW.kaqmnwj2wn
	  section.data(13).logicalSrcIdx = 65;
	  section.data(13).dtTransOffset = 13;
	
	  ;% rtDW.gytwfjza2q
	  section.data(14).logicalSrcIdx = 66;
	  section.data(14).dtTransOffset = 15;
	
	  ;% rtDW.awfq5ek0fh.PrevIndex
	  section.data(15).logicalSrcIdx = 67;
	  section.data(15).dtTransOffset = 16;
	
	  ;% rtDW.frrqi3axqr.PrevIndex
	  section.data(16).logicalSrcIdx = 68;
	  section.data(16).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% rtDW.ata4d5ulcr
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.c3h4wxu1yg
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2903976693;
  targMap.checksum1 = 1265714942;
  targMap.checksum2 = 460222312;
  targMap.checksum3 = 547042216;

